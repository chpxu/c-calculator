{
  description = "C environment";
  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs";
  };
  outputs = {
    self,
    nixpkgs,
  }: let
    system = "x86_64-linux";
    pkgs = import nixpkgs {inherit system;};
  in {
    devShells.${system}.default = pkgs.mkShell.override {stdenv = pkgs.gcc13Stdenv;} {
      packages = with pkgs; [glibc gcc13 binutils zlib gdb valgrind];
    };
    defaultPackage.${system} = with import nixpkgs {inherit system;};
      stdenv.mkDerivation {
        name = "calc";
        src = ./.;
        buildPhase = ''
          gcc ./calc.c -o -lm calc'';
        installPhase = "mkdir -p $out/bin; mkdir -p $out/lib; install -t $out/bin calc";
      };
  };
}
