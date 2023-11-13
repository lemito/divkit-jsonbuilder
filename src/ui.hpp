#pragma once

#include <string>
#include <string_view>

#include <userver/components/component_list.hpp>

namespace service_template {

std::string returnjson();

void AppendUi(userver::components::ComponentList &component_list);

} // namespace service_template
