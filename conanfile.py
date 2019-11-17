from conans import ConanFile
from conans import CMake


class Cis1CWUProtocol(ConanFile):
    name = "cis1_cwu_protocol"
    version = "0.0.4"
    description = "Protocol part of CWU protocol for cis1."
    author = "MokinIA <mia@tomsksoft.com>"
    generators = "cmake"
    settings = "os", "arch", "compiler", "build_type"
    exports = []
    exports_sources = ["CMakeLists.txt", "include/*"]
    requires = ("cis1_tpl/0.0.3@tomsksoft/cis1")

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        self.copy("*.h", dst="include/cis1_cwu_protocol", src="include")
