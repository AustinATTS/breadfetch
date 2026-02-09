load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")
load("//bazel/carbon_rules:defs.bzl", "carbon_binary")

cc_library(
    name = "display_lib",
    srcs = ["display.cc"],
    hdrs = ["//include:display.h"],
    includes = ["../include"],
)

cc_library(
    name = "system_info_lib",
    srcs = ["system_info.cc"],
    hdrs = ["//include:system_info.h"],
    includes = ["../include"],
)

carbon_binary(
    name = "breadfetch",
    srcs = ["main.carbon"],
    tags = ["no-sandbox"],
    visibility = ["//visibility:public"],
    deps = [
        ":display_lib",
        ":system_info_lib",
    ],
)
