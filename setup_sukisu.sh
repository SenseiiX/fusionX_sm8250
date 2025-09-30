rm -rf KernelSU
echo "Setting up SukiSU-Ultra"
curl -sSL "https://raw.githubusercontent.com/SukiSU-Ultra/SukiSU-Ultra/refs/heads/main/kernel/setup.sh" | bash -s nongki
(
  cd KernelSU/kernel
  echo "Adding more manager support..."
  sed -i '/{ EXPECTED_SIZE_SHIRKNEKO, EXPECTED_HASH_SHIRKNEKO }, \/\/ SukiSU/a\
\t{ 0x033b, "c371061b19d8c7d7d6133c6a9bafe198fa944e50c1b31c9d8daa8d7f1fc2d2d6"}, // official KernelSU\
\t{ 384, "7e0c6d7278a3bb8e364e0fcba95afaf3666cf5ff3c245a3b63c8833bd0445cc4" },   // 5ec1cff/KernelSU\
\t{ 0x396, "f415f4ed9435427e1fdf7f1fccd4dbc07b3d6b8751e4dbcec6f19671f427870b" }, // rsuntk/KernelSU\
\t{ 0x363, "4359c171f32543394cbc23ef908c4bb94cad7c8087002ba164c8230948c21549"},  // backslashxx/KernelSU\
\t{ 0x375, "484fcba6e6c43b1fb09700633bf2fb4758f13cb0b2f4457b80d075084b26c588" }, // KOWX712/KernelSU\
\t{ 0x3e6, "79e590113c4c4c0c222978e413a5faa801666957b1212a328e46c00c69821bf7" }, // rifsxd/KernelSU\
\t{ 0x39b, "593d4ce870c02468639efeef631e07ca4d852d63f154be56706229f9a5be0800" }, // TheWildJames/KernelSU' apk_sign.c
)
echo "Done (KSU, MKSU, RKSU, xxKSU, KOWSU, KSUN and WKSU)"
