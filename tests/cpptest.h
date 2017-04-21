/***************************************************************
 * Name:      cpptest.cpp
 * Author:    Mateusz Papiez ()
 * Created:   2017-01-07
 * Copyright: Mateusz Papiez ()
 * License:
 **************************************************************/


#ifndef CPPTEST_H_INCLUDED
#define CPPTEST_H_INCLUDED

#include <iostream>
#include <stdlib.h>

#define TEST_PASSED std::cout << "test passed" << std::endl
#define TEST_FAILED std::cout << "test failed" << std::endl

namespace cpptest{
    struct utest{
        private:
            static int passed;
            static int failed;
            static int all;
        public:
            static void assert(bool statement){
                if (statement){
                    utest::passed++;
                    TEST_PASSED;
                }
                else{
                    utest::failed++;
                    TEST_FAILED;
                }
                utest::all++;
            }

            ~utest(){
                std::cout<<std::endl<<"Made "<<utest::all<<" tests!";
                std::cout<<std::endl<<utest::passed<<" tests passed!";
                std::cout<<std::endl<<utest::failed<<" tests failed!"<<std::endl;
            }
    };
    utest t;
    int utest::passed;
    int utest::failed;
    int utest::all;
    void assert(bool statement){
            utest::assert(statement);
    }
    template <typename T, typename S> void assertEquals(T expResult, S result){
        bool statement;
        try{
            statement = (expResult==result);
        }catch(...){
            statement = false;
        }
        utest::assert(statement);

    }

}



#endif // CPPTEST_H_INCLUDED
