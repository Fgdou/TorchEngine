//
// Created by fgdou on 2/26/22.
//

#include "Log.h"

namespace Torch{
    Log::STATE state = Log::STATE::INFO;
    std::ostream* infoStream = &std::cout;
    std::ostream* warnStream = &std::cout;
    std::ostream* errorStream = &std::cerr;

    void Log::setLogState(Log::STATE s) {
        state = s;
    }
    void Log::setOutputStream(std::ostream &info, std::ostream &warn, std::ostream &error) {
        infoStream = &info;
        warnStream = &warn;
        errorStream = &error;
    }

    void Log::log(const char *str, const char *file, int line, Log::STATE s) {
        if(s > state)
            return;

        std::ostream* ref;
        std::string type;
        if(s == STATE::INFO) {
            ref = infoStream;
            type = "INFO";
        }else if(s == STATE::WARN) {
            ref = warnStream;
            type = "WARN";
        }else if(s == STATE::ERROR) {
            ref = errorStream;
            type = "ERRO";
        }
        std::ostream& out = *ref;

        out << "[" << type << "] " << file << ':' << line << " : " << str << std::endl;
    }
}