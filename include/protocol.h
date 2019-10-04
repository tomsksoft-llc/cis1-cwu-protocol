#pragma once

#include <string>

#include <tpl_reflect/meta_converter.h>
#include <tpl_reflect/json_engine.h>

namespace cis1
{

namespace cwu
{

struct log_entry
{
    std::chrono::time_point<std::chrono::system_clock> time;
    std::optional<std::string> session_id;
    uint64_t pid;
    uint64_t ppid;
    std::string message;

    static constexpr auto get_converter()
    {
        using namespace reflect;
        return make_meta_converter<log_entry>()
            .set_name(
                    CT_STRING("log_entry"))
            .add_field(
                    CT_STRING("time"),
                    ptr_v<&log_entry::time>())
            .add_field(
                    CT_STRING("session_id"),
                    ptr_v<&log_entry::session_id>())
            .add_field(
                    CT_STRING("message"),
                    ptr_v<&log_entry::message>())
            .add_field(
                    CT_STRING("pid"),
                    ptr_v<&log_entry::pid>())
            .add_field(
                    CT_STRING("ppid"),
                    ptr_v<&log_entry::ppid>())
            .done();
    }
};

} // namespace cwu

} // namespace cis1
