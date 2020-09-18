// swift-tools-version:5.3
import PackageDescription

let package = Package(
    name: "GLGeoRealtime",
    platforms: [
        .iOS(.v11)
    ],
    products: [

    ],
    dependencies: [],
    targets: [
        .binaryTarget(
            name: "GLGeoRealtime",
            path: "GLGeoRealtime.xcframework"
        )
    ]
)
