//ContextMenu.qml
import QtQuick 2.15
import QtQuick.Controls 2.15
import QtGraphicalEffects 1.15
import QtQml.Models 2.15
//import TreeItem 1.0

import "qrc:/mytypes"

Item {
    id: contextMenu
    property var currentIndex

    function popup(model) {

        if (model.itemType === /*TreeItem.LD*/ 1)
            ldMenu.popup()

        if (model.itemType === /*TreeItem.LN*/ 2)
            lnMenu.popup()

        currentIndex = model.qModelIndex

    }

    function addLn(lnClass) { treeModel.addLn(currentIndex, lnClass) }
    function addDo(cdc) { treeModel.addLn(currentIndex, cdc) }
    function deleteLd() { treeModel.deleteLd(currentIndex) }
    function deleteLn() { treeModel.deleteLn(currentIndex) }


    MyMenu {
        id: ldMenu

        MyMenu {
            title: "Add LN"

            MyMenu {
                title: "L"
                Action { text: "LLN0"; onTriggered: contextMenu.addLn(text) }
                Action { text: "LPHD"; onTriggered: contextMenu.addLn(text) }
                Action { text: "LCCH"; onTriggered: contextMenu.addLn(text) }
                Action { text: "LGOS"; onTriggered: contextMenu.addLn(text) }
                Action { text: "LSVS"; onTriggered: contextMenu.addLn(text) }
                Action { text: "LTIM"; onTriggered: contextMenu.addLn(text) }
                Action { text: "LTMS"; onTriggered: contextMenu.addLn(text) }
                Action { text: "LTRK"; onTriggered: contextMenu.addLn(text) }
            }

            MyMenu {
                title: "A"
                Action { text: "ANCR"; onTriggered: contextMenu.addLn(text) }
                Action { text: "ARCO"; onTriggered: contextMenu.addLn(text) }
                Action { text: "ARIS"; onTriggered: contextMenu.addLn(text) }
                Action { text: "ASEQ"; onTriggered: contextMenu.addLn(text) }
                Action { text: "ATCC"; onTriggered: contextMenu.addLn(text) }
                Action { text: "AVCO"; onTriggered: contextMenu.addLn(text) }
            }

            MyMenu {
                title: "C"
                Action { text: "CALH"; onTriggered: contextMenu.addLn(text) }
                Action { text: "CCGR"; onTriggered: contextMenu.addLn(text) }
                Action { text: "CILO"; onTriggered: contextMenu.addLn(text) }
                Action { text: "CPOW"; onTriggered: contextMenu.addLn(text) }
                Action { text: "CSWI"; onTriggered: contextMenu.addLn(text) }
                Action { text: "CSYN"; onTriggered: contextMenu.addLn(text) }
            }

            MyMenu {
                title: "F"
                Action { text: "FCNT"; onTriggered: contextMenu.addLn(text) }
                Action { text: "FCSD"; onTriggered: contextMenu.addLn(text) }
                Action { text: "FFIL"; onTriggered: contextMenu.addLn(text) }
                Action { text: "FLIM"; onTriggered: contextMenu.addLn(text) }
                Action { text: "FPID"; onTriggered: contextMenu.addLn(text) }
                Action { text: "FRMP"; onTriggered: contextMenu.addLn(text) }
                Action { text: "FSCC"; onTriggered: contextMenu.addLn(text) }
                Action { text: "FSCH"; onTriggered: contextMenu.addLn(text) }
                Action { text: "FSCH"; onTriggered: contextMenu.addLn(text) }
                Action { text: "FSPT"; onTriggered: contextMenu.addLn(text) }
                Action { text: "FXOT"; onTriggered: contextMenu.addLn(text) }
                Action { text: "FXUT"; onTriggered: contextMenu.addLn(text) }
            }

            MyMenu {
                title: "G"
                Action { text: "GAPC"; onTriggered: contextMenu.addLn(text) }
                Action { text: "GGIO"; onTriggered: contextMenu.addLn(text) }
                Action { text: "GLOG"; onTriggered: contextMenu.addLn(text) }
                Action { text: "GSAL"; onTriggered: contextMenu.addLn(text) }
            }

            MyMenu {
                title: "I"
                Action { text: "IARC"; onTriggered: contextMenu.addLn(text) }
                Action { text: "IHMI"; onTriggered: contextMenu.addLn(text) }
                Action { text: "ISAF"; onTriggered: contextMenu.addLn(text) }
                Action { text: "ITCI"; onTriggered: contextMenu.addLn(text) }
                Action { text: "ITMI"; onTriggered: contextMenu.addLn(text) }
                Action { text: "ITPC"; onTriggered: contextMenu.addLn(text) }
            }

            MyMenu {
                title: "K"
                Action { text: "KFAN"; onTriggered: contextMenu.addLn(text) }
                Action { text: "KFIL"; onTriggered: contextMenu.addLn(text) }
                Action { text: "KPMP"; onTriggered: contextMenu.addLn(text) }
                Action { text: "KTNK"; onTriggered: contextMenu.addLn(text) }
                Action { text: "KVLV"; onTriggered: contextMenu.addLn(text) }
            }

            MyMenu {
                title: "M"
                Action { text: "MENV"; onTriggered: contextMenu.addLn(text) }
                Action { text: "MFLK"; onTriggered: contextMenu.addLn(text) }
                Action { text: "MFLW"; onTriggered: contextMenu.addLn(text) }
                Action { text: "MHAI"; onTriggered: contextMenu.addLn(text) }
                Action { text: "MHAN"; onTriggered: contextMenu.addLn(text) }
                Action { text: "MHET"; onTriggered: contextMenu.addLn(text) }
                Action { text: "MHED"; onTriggered: contextMenu.addLn(text) }
                Action { text: "MHYD"; onTriggered: contextMenu.addLn(text) }
                Action { text: "MMDC"; onTriggered: contextMenu.addLn(text) }
                Action { text: "MMET"; onTriggered: contextMenu.addLn(text) }
                Action { text: "MMTN"; onTriggered: contextMenu.addLn(text) }
                Action { text: "MMTR"; onTriggered: contextMenu.addLn(text) }
                Action { text: "MMXN"; onTriggered: contextMenu.addLn(text) }
                Action { text: "MMXU"; onTriggered: contextMenu.addLn(text) }
                Action { text: "MSQI"; onTriggered: contextMenu.addLn(text) }
            }

            MyMenu {
                title: "P"
                Action { text: "PDIF"; onTriggered: contextMenu.addLn(text) }
                Action { text: "PDIR"; onTriggered: contextMenu.addLn(text) }
                Action { text: "PDIS"; onTriggered: contextMenu.addLn(text) }
                Action { text: "PDOP"; onTriggered: contextMenu.addLn(text) }
                Action { text: "PDUP"; onTriggered: contextMenu.addLn(text) }
                Action { text: "PFRC"; onTriggered: contextMenu.addLn(text) }
                Action { text: "PHAR"; onTriggered: contextMenu.addLn(text) }
                Action { text: "PHIZ"; onTriggered: contextMenu.addLn(text) }
                Action { text: "PIOC"; onTriggered: contextMenu.addLn(text) }
                Action { text: "PMRI"; onTriggered: contextMenu.addLn(text) }
                Action { text: "PMSS"; onTriggered: contextMenu.addLn(text) }
                Action { text: "POPF"; onTriggered: contextMenu.addLn(text) }
                Action { text: "PPAM"; onTriggered: contextMenu.addLn(text) }
                Action { text: "PRTR"; onTriggered: contextMenu.addLn(text) }
                Action { text: "PSCH"; onTriggered: contextMenu.addLn(text) }
                Action { text: "PSDE"; onTriggered: contextMenu.addLn(text) }
                Action { text: "PSOF"; onTriggered: contextMenu.addLn(text) }
                Action { text: "PTDV"; onTriggered: contextMenu.addLn(text) }
                Action { text: "PTEF"; onTriggered: contextMenu.addLn(text) }
                Action { text: "PTHF"; onTriggered: contextMenu.addLn(text) }
                Action { text: "PTOC"; onTriggered: contextMenu.addLn(text) }
                Action { text: "PTOF"; onTriggered: contextMenu.addLn(text) }
                Action { text: "PTOV"; onTriggered: contextMenu.addLn(text) }
                Action { text: "PTRC"; onTriggered: contextMenu.addLn(text) }
                Action { text: "PTTR"; onTriggered: contextMenu.addLn(text) }
                Action { text: "PTUC"; onTriggered: contextMenu.addLn(text) }
                Action { text: "PTUF"; onTriggered: contextMenu.addLn(text) }
                Action { text: "PTUV"; onTriggered: contextMenu.addLn(text) }
                Action { text: "PUPF"; onTriggered: contextMenu.addLn(text) }
                Action { text: "PVOC"; onTriggered: contextMenu.addLn(text) }
                Action { text: "PVPH"; onTriggered: contextMenu.addLn(text) }
                Action { text: "PZSU"; onTriggered: contextMenu.addLn(text) }
            }

            MyMenu {
                title: "Q"
                Action { text: "QFVR"; onTriggered: contextMenu.addLn(text) }
                Action { text: "QITR"; onTriggered: contextMenu.addLn(text) }
                Action { text: "QUIB"; onTriggered: contextMenu.addLn(text) }
                Action { text: "QVTR"; onTriggered: contextMenu.addLn(text) }
                Action { text: "QVUB"; onTriggered: contextMenu.addLn(text) }
                Action { text: "QVVR"; onTriggered: contextMenu.addLn(text) }
            }

            MyMenu {
                title: "P"
                Action { text: "RADR"; onTriggered: contextMenu.addLn(text) }
                Action { text: "RBDR"; onTriggered: contextMenu.addLn(text) }
                Action { text: "RBRF"; onTriggered: contextMenu.addLn(text) }
                Action { text: "RDIR"; onTriggered: contextMenu.addLn(text) }
                Action { text: "RDRE"; onTriggered: contextMenu.addLn(text) }
                Action { text: "RDRS"; onTriggered: contextMenu.addLn(text) }
                Action { text: "RFLO"; onTriggered: contextMenu.addLn(text) }
                Action { text: "RMXU"; onTriggered: contextMenu.addLn(text) }
                Action { text: "RPSB"; onTriggered: contextMenu.addLn(text) }
                Action { text: "RREC"; onTriggered: contextMenu.addLn(text) }
                Action { text: "RSYN"; onTriggered: contextMenu.addLn(text) }
            }

            MyMenu {
                title: "S"
                Action { text: "SARC"; onTriggered: contextMenu.addLn(text) }
                Action { text: "SCBR"; onTriggered: contextMenu.addLn(text) }
                Action { text: "SIMG"; onTriggered: contextMenu.addLn(text) }
                Action { text: "SIML"; onTriggered: contextMenu.addLn(text) }
                Action { text: "SLTC"; onTriggered: contextMenu.addLn(text) }
                Action { text: "SOPM"; onTriggered: contextMenu.addLn(text) }
                Action { text: "SPDC"; onTriggered: contextMenu.addLn(text) }
                Action { text: "SPRS"; onTriggered: contextMenu.addLn(text) }
                Action { text: "SPTR"; onTriggered: contextMenu.addLn(text) }
                Action { text: "SSWI"; onTriggered: contextMenu.addLn(text) }
                Action { text: "STMP"; onTriggered: contextMenu.addLn(text) }
                Action { text: "SVBR"; onTriggered: contextMenu.addLn(text) }
            }

            MyMenu {
                title: "T"
                Action { text: "TANG"; onTriggered: contextMenu.addLn(text) }
                Action { text: "TAXD"; onTriggered: contextMenu.addLn(text) }
                Action { text: "TCTR"; onTriggered: contextMenu.addLn(text) }
                Action { text: "TDST"; onTriggered: contextMenu.addLn(text) }
                Action { text: "TFLW"; onTriggered: contextMenu.addLn(text) }
                Action { text: "TFRQ"; onTriggered: contextMenu.addLn(text) }
                Action { text: "TGSN"; onTriggered: contextMenu.addLn(text) }
                Action { text: "THUM"; onTriggered: contextMenu.addLn(text) }
                Action { text: "TLVL"; onTriggered: contextMenu.addLn(text) }
                Action { text: "TMGF"; onTriggered: contextMenu.addLn(text) }
                Action { text: "TMVM"; onTriggered: contextMenu.addLn(text) }
                Action { text: "TPOS"; onTriggered: contextMenu.addLn(text) }
                Action { text: "TPRS"; onTriggered: contextMenu.addLn(text) }
                Action { text: "TRTN"; onTriggered: contextMenu.addLn(text) }
                Action { text: "TSND"; onTriggered: contextMenu.addLn(text) }
                Action { text: "TTMP"; onTriggered: contextMenu.addLn(text) }
                Action { text: "TTNS"; onTriggered: contextMenu.addLn(text) }
                Action { text: "TVBR"; onTriggered: contextMenu.addLn(text) }
                Action { text: "TVTR"; onTriggered: contextMenu.addLn(text) }
                Action { text: "TWPH"; onTriggered: contextMenu.addLn(text) }
            }

            MyMenu {
                title: "X"
                Action { text: "XCBR"; onTriggered: contextMenu.addLn(text) }
                Action { text: "XFUS"; onTriggered: contextMenu.addLn(text) }
                Action { text: "XSWI"; onTriggered: contextMenu.addLn(text) }
            }

            MyMenu {
                title: "X"
                Action { text: "YEFN"; onTriggered: contextMenu.addLn(text) }
                Action { text: "YLTC"; onTriggered: contextMenu.addLn(text) }
                Action { text: "YPSH"; onTriggered: contextMenu.addLn(text) }
                Action { text: "YPTR"; onTriggered: contextMenu.addLn(text) }
            }

            MyMenu {
                title: "Z"
                Action { text: "ZAXN"; onTriggered: contextMenu.addLn(text) }
                Action { text: "ZBAT"; onTriggered: contextMenu.addLn(text) }
                Action { text: "ZBSH"; onTriggered: contextMenu.addLn(text) }
                Action { text: "ZCAB"; onTriggered: contextMenu.addLn(text) }
                Action { text: "ZCAP"; onTriggered: contextMenu.addLn(text) }
                Action { text: "ZCON"; onTriggered: contextMenu.addLn(text) }
                Action { text: "ZGEN"; onTriggered: contextMenu.addLn(text) }
                Action { text: "ZGIL"; onTriggered: contextMenu.addLn(text) }
                Action { text: "ZLIN"; onTriggered: contextMenu.addLn(text) }
                Action { text: "ZMOT"; onTriggered: contextMenu.addLn(text) }
                Action { text: "ZREA"; onTriggered: contextMenu.addLn(text) }
                Action { text: "ZRES"; onTriggered: contextMenu.addLn(text) }
                Action { text: "ZRRC"; onTriggered: contextMenu.addLn(text) }
                Action { text: "ZSAR"; onTriggered: contextMenu.addLn(text) }
                Action { text: "ZSCR"; onTriggered: contextMenu.addLn(text) }
                Action { text: "ZSMC"; onTriggered: contextMenu.addLn(text) }
                Action { text: "ZTCF"; onTriggered: contextMenu.addLn(text) }
                Action { text: "ZTCR"; onTriggered: contextMenu.addLn(text) }
            }

        }

        Action { text: "Delete LD"; onTriggered:  contextMenu.deleteLd()}
    }





    MyMenu {
        id: lnMenu

        MyMenu {
            title: "Add DO"

            MyMenu {
                title: "Status"
                Action { text: "SPS"; onTriggered: contextMenu.addDo(text) }
                Action { text: "DPS"; onTriggered: contextMenu.addDo(text) }
                Action { text: "INS"; onTriggered: contextMenu.addDo(text) }
                Action { text: "ENS"; onTriggered: contextMenu.addDo(text) }
                Action { text: "ACT"; onTriggered: contextMenu.addDo(text) }
                Action { text: "ACD"; onTriggered: contextMenu.addDo(text) }
                Action { text: "SEC"; onTriggered: contextMenu.addDo(text) }
                Action { text: "BCR"; onTriggered: contextMenu.addDo(text) }
                Action { text: "HST"; onTriggered: contextMenu.addDo(text) }
                Action { text: "VSS"; onTriggered: contextMenu.addDo(text) }
                Action { text: "ORS"; onTriggered: contextMenu.addDo(text) }
            }

            MyMenu {
                title: "Measuring"
                Action { text: "MV"; onTriggered: contextMenu.addDO(text) }
                Action { text: "CMV"; onTriggered: contextMenu.addDO(text) }
                Action { text: "SAV"; onTriggered: contextMenu.addDO(text) }
                Action { text: "WYE"; onTriggered: contextMenu.addDO(text) }
                Action { text: "DEL"; onTriggered: contextMenu.addDO(text) }
                Action { text: "SEQ"; onTriggered: contextMenu.addDO(text) }
                Action { text: "HMV"; onTriggered: contextMenu.addDO(text) }
                Action { text: "HWYE"; onTriggered: contextMenu.addDO(text) }
                Action { text: "HDEL"; onTriggered: contextMenu.addDO(text) }
            }

            MyMenu {
                title: "Control"
                Action { text: "SPC"; onTriggered: contextMenu.addDO(text) }
                Action { text: "DPC"; onTriggered: contextMenu.addDO(text) }
                Action { text: "INC"; onTriggered: contextMenu.addDo(text) }
                Action { text: "ENC"; onTriggered: contextMenu.addDo(text) }
                Action { text: "BSC"; onTriggered: contextMenu.addDo(text) }
                Action { text: "ISC"; onTriggered: contextMenu.addDo(text) }
                Action { text: "APC"; onTriggered: contextMenu.addDo(text) }
                Action { text: "BAC"; onTriggered: contextMenu.addDo(text) }
            }

            MyMenu {
                title: "Setting"
                Action { text: "SPG"; onTriggered: contextMenu.addDO(text) }
                Action { text: "ING"; onTriggered: contextMenu.addDO(text) }
                Action { text: "ENG"; onTriggered: contextMenu.addDO(text) }
                Action { text: "ORG"; onTriggered: contextMenu.addDO(text) }
                Action { text: "TSG"; onTriggered: contextMenu.addDO(text) }
                Action { text: "CUG"; onTriggered: contextMenu.addDO(text) }
                Action { text: "VSG"; onTriggered: contextMenu.addDO(text) }
                Action { text: "ASG"; onTriggered: contextMenu.addDO(text) }
                Action { text: "CURVE"; onTriggered: contextMenu.addDO(text) }
                Action { text: "CSG"; onTriggered: contextMenu.addDO(text) }
            }

            MyMenu {
                title: "Description"
                Action { text: "DPL"; onTriggered: contextMenu.addDO(text) }
                Action { text: "LPL"; onTriggered: contextMenu.addDO(text) }
                Action { text: "CSD"; onTriggered: contextMenu.addDO(text) }
                Action { text: "VSD"; onTriggered: contextMenu.addDO(text) }
            }

            MyMenu {
                title: "Service Tracking"
                Action { text: "CST"; onTriggered: contextMenu.addDO(text) }
                Action { text: "BTS"; onTriggered: contextMenu.addDO(text) }
                Action { text: "UTS"; onTriggered: contextMenu.addDO(text) }
                Action { text: "LTS"; onTriggered: contextMenu.addDO(text) }
                Action { text: "GTS"; onTriggered: contextMenu.addDO(text) }
                Action { text: "MTS"; onTriggered: contextMenu.addDO(text) }
                Action { text: "NTS"; onTriggered: contextMenu.addDO(text) }
                Action { text: "STS"; onTriggered: contextMenu.addDO(text) }
            }
        }

        Action { text: "Delete LN"; onTriggered: contextMenu.deleteLn() }
    }
}
