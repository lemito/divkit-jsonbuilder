#include "ui.hpp"

#include <fmt/format.h>

#include <userver/server/handlers/http_handler_base.hpp>

namespace service_template {

namespace {

class Ui final : public userver::server::handlers::HttpHandlerBase {
 public:
  static constexpr std::string_view kName = "handler-ui";

  using HttpHandlerBase::HttpHandlerBase;

  std::string HandleRequestThrow(
      const userver::server::http::HttpRequest &request,
      userver::server::request::RequestContext &) const override {
    return service_template::returnjson();
  }
};

} // namespace

std::string returnjson() {
  userver::formats::json::ValueBuilder text{userver::formats::json::Type::kObject};

  text["type"] = "text";
  text["title"] = "order";
  text["color"] = "#FFFFFF";

  userver::formats::json::Value json = text.ExtractValue();

  return userver::formats::json::ToString(json);
}

void AppendUi(userver::components::ComponentList &component_list) {
  component_list.Append<Ui>();
}

} // namespace service_template
