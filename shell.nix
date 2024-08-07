{
  pkgs ? import <nixpkgs> { },
}:
pkgs.llvmPackages.stdenv.mkDerivation {

  name = "Development";
  buildInputs = with pkgs.buildPackages; [
    glfw-wayland
    libglvnd
    libglvnd.dev
  ];
  # nativeBuildInputs is usually what you want -- tools you need to run
  nativeBuildInputs = with pkgs.buildPackages; [
    gnumake
    cmake
    vcpkg
    clang
    clang-tools
    pkg-config
  ];

  shellHook = ''
    export VCPKG_ROOT="${pkgs.vcpkg.outPath}/share/vcpkg";
    # export CC="${pkgs.clang.outPath}/bin/clang";
    # export CXX="${pkgs.clang.outPath}/bin/clang++";
  '';
}
