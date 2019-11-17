#pragma once

#include <string>

#include <tpl_reflect/meta_converter.h>
#include <tpl_reflect/json_engine.h>

namespace cis1
{

namespace cwu
{

struct session_auth
{
    std::string session_token;
    std::string session_id;
    uint64_t pid;
    uint64_t ppid;

    static constexpr auto get_converter()
    {
        using namespace reflect;
        return make_meta_converter<session_auth>()
            .set_name(
                    CT_STRING("cwu"),
                    CT_STRING("session_auth"))
            .add_field(
                    CT_STRING("session_token"),
                    ptr_v<&session_auth::session_token>())
            .add_field(
                    CT_STRING("session_id"),
                    ptr_v<&session_auth::session_id>())
            .add_field(
                    CT_STRING("pid"),
                    ptr_v<&session_auth::pid>())
            .add_field(
                    CT_STRING("ppid"),
                    ptr_v<&session_auth::ppid>())
            .done();
    }
};

struct log_entry
{
    std::chrono::time_point<std::chrono::system_clock> time;
    std::string message;

    static constexpr auto get_converter()
    {
        using namespace reflect;
        return make_meta_converter<log_entry>()
            .set_name(
                    CT_STRING("cwu"),
                    CT_STRING("log_entry"))
            .add_field(
                    CT_STRING("time"),
                    ptr_v<&log_entry::time>())
            .add_field(
                    CT_STRING("message"),
                    ptr_v<&log_entry::message>())
            .done();
    }
};

} // namespace cwu

} // namespace cis1
