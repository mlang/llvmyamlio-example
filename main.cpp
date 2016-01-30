#include <llvm/Support/YAMLTraits.h>

struct configuration {
  std::string braille_locale = "Unicode-Braille";
  int width = 32;
};

namespace llvm {
  namespace yaml {
    template <> struct MappingTraits<::configuration> {
      static void mapping(yaml::IO &io, ::configuration &conf) {
        io.mapOptional("braille_locale", conf.braille_locale);
        io.mapOptional("width",          conf.width);
      }
    };
  }
}

int main()
{
  configuration conf;
  llvm::yaml::Output yout(llvm::outs());
  yout << conf;

  return EXIT_SUCCESS;
}
