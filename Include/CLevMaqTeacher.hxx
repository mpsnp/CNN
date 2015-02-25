#ifndef H_LEV_MAQ_TEACHER
#define H_LEV_MAQ_TEACHER

#include "CTeacher.hxx"

namespace CNN
{
    class CLevMaqTeacher : public CTeacher
    {
    private:
        TLearningData _learningData;
        int _stripLength;
        static void _Unbias(double *p, double *x, int m, int n, void *data);
    public:
        CLevMaqTeacher();
        ~CLevMaqTeacher();
        
        /**
         * @brief Trains specified network.
         * @note Currently it supports only CPerceptron.
         * @param LearningData Learning data.
         */
        void Teach(TLearningData LearningData);
    };
};

#endif
