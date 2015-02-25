#include "CLevMaqTeacher.hxx"
#include <levmar.h>
#include <algorithm>
#include <iostream>

CNN::CLevMaqTeacher::CLevMaqTeacher()
{
    
}

CNN::CLevMaqTeacher::~CLevMaqTeacher()
{
    
}

void CNN::CLevMaqTeacher::_Unbias(double *p, double *x, int m, int n, void *data)
{
    CLevMaqTeacher *teacher = (CLevMaqTeacher *)data;
    teacher->_TrainedNetwork->MapFromArray(p, m);
    int k = 0;
    for (auto lp : teacher->_learningData)
    {
        TOutputVector result = teacher->_TrainedNetwork->Calculate(lp.first);
        for (int j = 0; j < result.size(); j++)
        {
            x[k++] = result[j];
        }
    }
//    for (int i = 0; i < n; i++)
//        printf("%.5f : ", x[i]);
//    std::cout << std::endl;
}

void CNN::CLevMaqTeacher::Teach(TLearningData LearningData)
{
    this->_learningData = LearningData;
    int mapLength = 0;
    double *map = NULL;
    _TrainedNetwork->MapToArray(map, mapLength);
    
    _stripLength = LearningData[0].second.size() * (int)LearningData.size();
    int unbLength = std::max(mapLength, _stripLength);
    double *unb = new double[unbLength];
    int k = 0;
    for (auto lp : this->_learningData)
    {
        for (int j = 0; j < lp.second.size(); j++)
            unb[k++] = lp.second[j];
    }
//    for (int i = 0; i < unbLength; i++)
//        std::cout << unb[i] << ' ';
//    std::cout << std::endl;
    
    double opts[LM_OPTS_SZ], info[LM_INFO_SZ];
    opts[0]=0.00000001; opts[1]=1E-20; opts[2]=1E-20; opts[3]=1E-20; opts[4]= 1E-20;
    
    int ret = dlevmar_dif(_Unbias, map, unb, mapLength, unbLength, 100000, opts, info, NULL, NULL, this);

    printf("Levenberg-Marquardt returned %d in %g iter, reason %g\nSolution: ", ret, info[5], info[6]);
    printf("\n\nMinimization info:\n");
    for(int i=0; i<LM_INFO_SZ; ++i)
        printf("%g ", info[i]);
    printf("\n");
    
    _TrainedNetwork->MapFromArray(map, mapLength);
    
    delete [] map;
    delete [] unb;
}
