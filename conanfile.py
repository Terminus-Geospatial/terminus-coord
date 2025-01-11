#    File:    conanfile.py
#    Author:  Marvin Smith
#    Date:    1/9/2025
from conan import ConanFile
from conan.tools.cmake import CMake, CMakeToolchain, CMakeDeps
from conan.tools.files import copy

class ConanProject(ConanFile):

    name = "terminus_coord"
    version = "0.0.1"

    license = "MIT"
    author = "Marvin Smith <marvin.smith@terminus-geo.com>"
    url = "https://github.com/Terminus-Geospatial/terminus-coord"
    description = "Terminus C++ Coordinate Conversion API"
    topics = ("terminus", "coord")

    options = { "shared": [True, False],
                "with_tests": [True, False],
                "with_docs": [True, False],
                "with_coverage": [True, False]
    }

    default_options = { "shared": True,
                        "with_tests": True,
                        "with_docs": True,
                        "with_coverage": False,
                        "boost/*:shared": True,
                        "terminus_log/*:shared": True }

    settings = "os", "compiler", "build_type", "arch"

    def build_requirements(self):
        self.test_requires("gtest/1.15.0")
        self.tool_requires("terminus_cmake/1.0.5")

    def requirements(self):
        self.requires("boost/1.86.0")
        self.requires("tomlplusplus/3.4.0")
        self.requires("terminus_core/0.0.9")
        self.requires("terminus_log/0.0.7")
        self.requires("terminus_math/0.0.15")
        self.requires("terminus_outcome/0.0.6")

    def _configure_cmake(self):
        cmake = CMake(self)
        cmake.configure()
        return cmake

    def generate(self):
        tc = CMakeToolchain(self)
        tc.variables["CONAN_PKG_NAME"]        = self.name
        tc.variables["CONAN_PKG_VERSION"]     = self.version
        tc.variables["CONAN_PKG_DESCRIPTION"] = self.description
        tc.variables["CONAN_PKG_URL"]         = self.url

        tc.variables["TERMINUS_COORD_ENABLE_TESTS"]    = self.options.with_tests
        tc.variables["TERMINUS_COORD_ENABLE_DOCS"]     = self.options.with_docs
        tc.variables["TERMINUS_COORD_ENABLE_COVERAGE"] = self.options.with_coverage
        tc.generate()

        deps = CMakeDeps(self)
        deps.generate()

    def build(self):
        cmake = self._configure_cmake()
        cmake.build()

    def package(self):
        cmake = self._configure_cmake()
        cmake.install()

    def package_info(self):
        self.cpp_info.libs = ["terminus_coord"]

    def package_id(self):
        self.info.clear()

    def export_sources(self):

        for p in [ "CMakeLists.txt", "include/*", "src/*", "test/*", "README.md" ]:
            copy( self,
                  p,
                  self.recipe_folder,
                  self.export_sources_folder )
