# Standard settings for a Qt based project

QT += core gui xml network widgets svg
lessThan(QT_MAJOR_VERSION, 6){
    QT += xmlpatterns
}
greaterThan(QT_MAJOR_VERSION, 5){
    QT += svgwidgets
}

