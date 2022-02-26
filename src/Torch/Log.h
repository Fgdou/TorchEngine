//
// Created by fgdou on 2/26/22.
//

#ifndef SANDBOX_LOG_H
#define SANDBOX_LOG_H

#include <iostream>

namespace Torch{
    class Log{
    public:

        #define LOG_INFO(...){\
                    char buff[100];\
                    sprintf(buff, __VA_ARGS__);\
                    Torch::Log::log(buff, __FILE__, __LINE__, Torch::Log::STATE::INFO);}

        #define LOG_WARN(...){\
                    char buff[100];\
                    sprintf(buff, __VA_ARGS__);\
                    Torch::Log::log(buff, __FILE__, __LINE__, Torch::Log::STATE::WARN);}


        #define LOG_ERROR(...){\
                    char buff[100];\
                    sprintf(buff, __VA_ARGS__);\
                    Torch::Log::log(buff, __FILE__, __LINE__, Torch::Log::STATE::ERROR);}

        enum STATE{
            INFO = 2,
            WARN = 1,
            ERROR = 0
        };
        static void setLogState(STATE state);
        static void setOutputStream(std::ostream& info, std::ostream& warn, std::ostream& error);
        static void log(const char* str, const char* file, int line, STATE state);
    };


}


#endif //SANDBOX_LOG_H
