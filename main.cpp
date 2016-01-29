#include <llvm/Support/YAMLTraits.h>

struct Foo {
  int size;
};

namespace llvm { namespace yaml {

  template <>
  struct MappingTraits<Foo> {
    static void mapping(IO &io, Foo &foo) {
      io.mapOptional("size",      foo.size);
    }
  };

}}

int main()
{
  Foo foo { 1 };
  llvm::yaml::Output yout(llvm::outs());
  yout << foo;

  return EXIT_SUCCESS;
}
