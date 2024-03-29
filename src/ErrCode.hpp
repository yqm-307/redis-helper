#pragma once
#include <bbt/base/errcode/Errcode.hpp>
#include <string>

namespace bbt::database::redis::err
{

enum RedisErrType
{
    ConnectionFailed = 1,

    Comm_ParamIsNull = 2,

    Reply_Err        = 3,
    Reply_UnExpectedType    = 4,
    Reply_IsNil      = 5,
};

class RedisErr:
    public bbt::errcode::Errcode<bbt::database::redis::err::RedisErrType>
{
public:
    RedisErr(const std::string& errinfo, RedisErrType errtype):Errcode(errinfo, errtype) {}
    ~RedisErr() {}

    std::string What() { return GetMsg(); }
    int Type() { return GetErrType(); }
private:
};

} // namespace bbt::database::redis