import QtQuick 2.4
//import QtQuick.XmlListModel 2.0
//XmlListModel{
//    id: mod
//    source: "http://xml.nsu.ru/xml/cd_catalog.xml"
//    query: "/CATALOG/CD"
//    XmlRole{name: "title"; query: "TITLE/string()"}
//    XmlRole{name: "artist"; query: "ARTIST/string()"}
//    XmlRole{name: "country"; query: "COUNTRY/string()"}
//    XmlRole{name: "company"; query: "COMPANY/string()"}
//    XmlRole{name: "price"; query: "PRICE/string()"}
//    XmlRole{name: "year"; query: "YEAR/string()"}
//}

ListModel {
    id:  mod
    ListElement {
        artist: "Amaranthe"
        album: "Amaranthe"
        year: 2011
        cover: "qrc:///covers/Amaranthe.png"
    }
    ListElement {
        artist: "Dark Princess"
        album: "Without You"
        year: 2005
        cover: "qrc:///covers/WithoutYou.png"
    }
    ListElement {
        artist: "Within Temptation"
        album: "The Unforgiving"
        year: 2011
        cover: "qrc:///covers/TheUnforgiving.png"
    }
    ListElement {
        artist: "Evanescence"
        album: "Fallen"
        year: 2003
        cover: "qrc:///covers/Fallen.png"
    }
    ListElement {
        artist: "Tristania"
        album: "Rubicon"
        year: 2010
        cover: "qrc:///covers/Rubicon.png"
    }
    ListElement {
        artist: "Epica"
        album: "The Divine Conspiracy"
        year: 2007
        cover: "qrc:///covers/TheDivineConspirancy.png"
    }
    ListElement {
        artist: "Delain"
        album: "April Rain"
        year: 2010
        cover: "qrc:///covers/AprilRain.png"
    }
    ListElement {
        artist: "Sirenia"
        album: "The End of it All"
        year: 2011
        cover: "qrc:///covers/NineDestiniesAndADownfall.png"
    }
    ListElement {
        artist: "Nightwish"
        album: "Dark Passion Play"
        year: 2007
        cover: "qrc:///covers/DarkPassionPlay.png"
    }
}
