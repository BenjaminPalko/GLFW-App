{
  pkgs ? import <nixpkgs> { },
}:
pkgs.llvmPackages.stdenv.mkDerivation {

  name = "Development";
  buildInputs = with pkgs.buildPackages; [
    fmt
    fmt.dev
    glfw-wayland
    libGL
    libGL.dev
  ];
  # nativeBuildInputs is usually what you want -- tools you need to run
  nativeBuildInputs = with pkgs.buildPackages; [
    meson
    ninja
    gnumake
    clang
    clang-tools
    pkg-config
  ];

  shellHook = '''';
}
