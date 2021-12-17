from PyQt5.QtWidgets import QWidget
from PyQt5.QtGui import (
    QColor, QPainterPath, QFont, QPainter, QLinearGradient, QBrush, QPen, QFontMetrics,
    QRadialGradient, QPixmap, QTransform
)
from PyQt5.QtCore import QPoint, QRectF
from PyQt5.Qt import Qt
import math


class CustomButton(QWidget):
    def __init__(self, parent=None):
        super(CustomButton, self).__init__(parent)
        self.m_pressIndex = 0
        self.m_enterIndex = 0
        self.m_isMouseEntered = False
        self.m_isMousePressed = False
        self.m_radius = 80
        self.m_arcLength = 55
        self.mCenterRound = QPoint(0, 0)
        self.m_bTextModeEn = False
        self.setMouseTracking(True)
        self.mSectorColor = QColor(38, 38, 38)
        self.m_arcPathList = []
        self.m_colorList = []
        self.m_textPathList = []
        self.mCurWorkRegion = []
        self.QUADRANT_UP = 1
        self.QUADRANT_LEFT = 2
        self.QUADRANT_DOWN = 3
        self.QUADRANT_RIGHT = 4
        self.M_PI = 3.14159265358979323846

        self.initButton()
        self.setWidgetStyle("Bright")
        self.setAxesVertical(False)

        self.x = 0
        self.y = 0

    def setWidgetStyle(self, style):
        if (style == "Bright"):
            self.mSectorColor = QColor(238, 241, 240)
            self.colorSPL = QColor(63, 155, 178)
            self.colorBKG = QColor(193, 199, 209)

            self.colorSectorUp2 = QColor(240, 243, 208)
            self.colorSectorUp = QColor(239, 242, 247)
            self.colorSectorDown = QColor(221, 225, 231)

            self.colorbgGradient0 = QColor(175, 180, 191)
            self.colorbgGradient1 = QColor(239, 242, 247)

            self.colorExcircle0 = QColor(211, 215, 223)
            self.colorExcircle5 = QColor(231, 235, 240)
            self.colorExcircle9 = QColor(182, 187, 197)
            self.colorInnerCircle0 = QColor(45, 48, 56)
            self.colorInnerCircle9 = QColor(30, 32, 37)
        else:
            self.mSectorColor = QColor(38, 38, 38)
            self.colorSPL = QColor(32, 149, 216)
            self.colorBKG = QColor(41, 44, 50)

            self.colorSectorUp2 = QColor(68, 68, 68)
            self.colorSectorUp = QColor(60, 60, 60)
            self.colorSectorDown = QColor(22, 22, 22)

            self.colorbgGradient0 = QColor(24, 24, 24)
            self.colorbgGradient1 = QColor(53, 57, 63)

            self.colorExcircle0 = QColor(68, 68, 68)
            self.colorExcircle5 = QColor(37, 40, 46)
            self.colorExcircle9 = QColor(22, 22, 22)
            self.colorInnerCircle0 = QColor(45, 48, 56)
            self.colorInnerCircle9 = QColor(30, 32, 37)
        self.update()

    def setRadiusValue(self, radius):
        self.m_radius = radius

    def setArcLength(self, arcLength):
        self.m_arcLength = arcLength

    def drawRotatedText(self, painter, degrees, x, y, text):
        painter.save()  # 保存原来坐标系统
        painter.translate(x, y)  # 平移坐标原点到x， y
        painter.rotate(degrees)  # 坐标旋转degrees度
        painter.drawText(0, 0, text)  # 在原点绘制文本
        painter.restore()  # 回复原来的坐标系统

    def setAxesVertical(self, axesVertical):
        self.mAxesVertical = axesVertical
        if (self.mAxesVertical == False):
            self.addArc(1, 0, 45, 90, self.mSectorColor)
            self.addArc(0, 1, 135, 90, self.mSectorColor)
            self.addArc(-1, 0, 225, 90, self.mSectorColor)
            self.addArc(0, -1, 315, 90, self.mSectorColor)
        else:
            self.addArc(1, 0, 0, 90, self.mSectorColor)
            self.addArc(0, 1, 90, 90, self.mSectorColor)
            self.addArc(-1, 0, 180, 90, self.mSectorColor)
            self.addArc(0, -1, 270, 90, self.mSectorColor)

        # 绘制中心圆
        self.centerRoundPath = QPainterPath()
        self.centerRoundPath.addEllipse(QPoint(0, 0), self.m_radius - self.m_arcLength + 2,
                                        self.m_radius - self.m_arcLength + 2)
        self.m_arcPathList.append(self.centerRoundPath)
        self.m_colorList.append(QColor(255, 255, 255))

        # 添加文字
        self.font = QFont()
        self.font.setFamily("Microsoft YaHei")
        self.font.setPointSize(14)

        for i in range(len(self.m_arcPathList)):
            painterPath = QPainterPath()
            self.m_textPathList.append(painterPath)

        self.mStrUp = "前"
        self.mStrLeft = "左"
        self.mStrDown = "后"
        self.mStrRight = "右"
        self.update()

    def initButton(self):
        self.addArc(1, 0, 45, 90, self.mSectorColor)
        self.addArc(0, 1, 135, 90, self.mSectorColor)
        self.addArc(-1, 0, 225, 90, self.mSectorColor)
        self.addArc(0, -1, 315, 90, self.mSectorColor)

        # 绘制中心圆
        self.centerRoundPath = QPainterPath()
        self.centerRoundPath.addEllipse(QPoint(0, 0), self.m_radius - self.m_arcLength + 2,
                                        self.m_radius - self.m_arcLength + 2)
        self.m_arcPathList.append(self.centerRoundPath)
        self.m_colorList.append(QColor(255, 255, 255))

        # 添加文字
        font = QFont()
        font.setFamily("Microsoft YaHei")
        font.setPointSize(14)

        for i in range(len(self.m_arcPathList)):
            painterPath = QPainterPath()
            self.m_textPathList.append(painterPath)

        self.mStrUp = "前"
        self.mStrLeft = "左"
        self.mStrDown = "后"
        self.mStrRight = "右"

    def paintEvent(self, QPaintEvent):
        painter = QPainter(self)
        painter.setRenderHint(QPainter.HighQualityAntialiasing, True)

        painter.setPen(Qt.NoPen)
        painter.translate(self.width() >> 1, self.height() >> 1)

        # 背景色，分割线颜色
        painter.setBrush(self.colorBKG)
        painter.drawEllipse(QPoint(0, 0), self.m_radius + 8, self.m_radius + 8)

        linearGradient = QLinearGradient(0, -self.m_radius - 2, 0, self.m_radius + 2)
        linearGradient.setColorAt(0.0, self.colorSectorUp2)
        linearGradient.setColorAt(0.9, self.colorSectorDown)
        painter.setBrush(QBrush(linearGradient))
        painter.drawEllipse(QPoint(0, 0), self.m_radius + 2, self.m_radius + 2)

        linearGradient = QLinearGradient(0, -self.m_radius, 0, self.m_radius)
        linearGradient.setColorAt(0.0, self.colorSectorUp)
        linearGradient.setColorAt(0.9, self.colorSectorDown)
        painter.setBrush(QBrush(linearGradient))
        painter.drawEllipse(QPoint(0, 0), self.m_radius, self.m_radius)

        bgGradient = QLinearGradient(0, -37, 0, 37)
        bgGradient.setColorAt(0.0, self.colorbgGradient0)
        bgGradient.setColorAt(1.0, self.colorbgGradient1)
        painter.setBrush(bgGradient)
        painter.drawEllipse(QPoint(0, 0), self.m_radius - self.m_arcLength + 4,
                            self.m_radius - self.m_arcLength + 4)

        count = 4
        for i in range(count):
            painter.save()
            if (self.mAxesVertical == False):
                painter.rotate(45 + 90 * i)

            else:
                painter.rotate(0 + 90 * i)
            painter.setPen(QPen(self.colorBKG, 3, Qt.SolidLine))
            painter.drawLine(0, self.m_radius - self.m_arcLength + 5, 0, self.m_radius + 5)
            painter.setPen(QPen(self.colorSPL, 3, Qt.SolidLine, Qt.RoundCap))
            painter.drawLine(0, self.m_radius - self.m_arcLength + 6, 0, 40)
            painter.setPen(QPen(self.colorSPL, 3, Qt.SolidLine))
            painter.drawLine(0, 40, 0, self.m_radius - 5)
            painter.restore()

        linearGradient = QLinearGradient(0, self.mCenterRound.y() - self.m_radius + self.m_arcLength - 1, 0,
                                         self.mCenterRound.y() + self.m_radius - self.m_arcLength + 1)
        linearGradient.setColorAt(0.0, self.colorExcircle0)
        linearGradient.setColorAt(0.0, self.colorExcircle5)
        linearGradient.setColorAt(0.9, self.colorExcircle9)

        painter.setBrush(QBrush(linearGradient))
        painter.drawEllipse(self.mCenterRound, self.m_radius - self.m_arcLength, self.m_radius - self.m_arcLength)

        painter.setRenderHint(QPainter.SmoothPixmapTransform, True)

        if self.mAxesVertical == False:
            leftmatrix = QTransform()
            if (self.QUADRANT_UP in self.mCurWorkRegion):
                painter.drawPixmap(-30, -60, 60, 30, self.mDegreePixmap_y)
                leftmatrix.reset()
            if (self.QUADRANT_LEFT in self.mCurWorkRegion):
                leftmatrix.rotate(270)
                mDegreePixmap = self.mDegreePixmap_x.transformed(leftmatrix, Qt.SmoothTransformation)
                painter.drawPixmap(-60, -30, 30, 60, mDegreePixmap)
                leftmatrix.reset()
            if (self.QUADRANT_DOWN in self.mCurWorkRegion):
                leftmatrix.rotate(180)
                mDegreePixmap = self.mDegreePixmap_y.transformed(leftmatrix, Qt.SmoothTransformation)
                painter.drawPixmap(-30, 30, 60, 30, mDegreePixmap)
                leftmatrix.reset()
            if (self.QUADRANT_RIGHT in self.mCurWorkRegion):
                leftmatrix.rotate(90)
                mDegreePixmap = self.mDegreePixmap_x.transformed(leftmatrix, Qt.SmoothTransformation)
                painter.drawPixmap(30, -30, 30, 60, mDegreePixmap)
                leftmatrix.reset()

        font = QFont()
        font.setFamily("Microsoft YaHei")
        font.setPointSize(12)
        painter.setFont(font)
        painter.setPen(QColor(170, 170, 170))
        if self.mAxesVertical == True:
            painter.drawText(QPoint(-60, -40), self.mStrUp)
            painter.drawText(QPoint(30, -40), self.mStrLeft)

            painter.drawText(QPoint(-80, 40), self.mStrDown)
            painter.drawText(QPoint(20, 40), self.mStrRight)
        else:

            fm = QFontMetrics(font)
            rText = 65
            nHeight = fm.height() - 4
            iTotalWidth = fm.width(self.mStrUp)
            painter.save()
            painter.rotate(-90 * iTotalWidth / (rText * self.M_PI))
            for i in range(len(self.mStrUp)):
                self.nWidth = fm.width(self.mStrUp[i])
                painter.rotate(90 * self.nWidth / (rText * self.M_PI))
                painter.drawText(-self.nWidth / 2, -1 * rText, self.mStrUp[i])
                painter.rotate(90 * self.nWidth / (rText * self.M_PI))
            painter.restore()
            painter.save()
            if (self.m_bTextModeEn):

                iTotalWidth = fm.width(self.mStrRight)
                painter.rotate(90 - 90 * iTotalWidth / (rText * self.M_PI))
                for i in range(len(self.mStrRight)):
                    nWidth = fm.width(self.mStrRight[i])
                    painter.rotate(90 * nWidth / (rText * self.M_PI))
                    painter.drawText(-nWidth / 2, -1 * rText, self.mStrRight[i])
                    painter.rotate(90 * nWidth / (rText * self.M_PI))
            else:
                iTotalWidth = nHeight * len(self.mStrRight)
                painter.rotate(-90 * iTotalWidth / (rText * self.M_PI))
                for i in range(len(self.mStrRight)):
                    painter.rotate(90 * nHeight / (rText * self.M_PI))
                    painter.drawText(rText - 5, nHeight / 2, self.mStrRight[i])
                    painter.rotate(90 * nHeight / (rText * self.M_PI))
            painter.restore()

            painter.save()
            iTotalWidth = fm.width(self.mStrDown)
            painter.rotate(90 * iTotalWidth / (rText * self.M_PI))
            for i in range(len(self.mStrDown)):
                nWidth = fm.width(self.mStrDown[i])
                painter.rotate(-90 * nWidth / (rText * self.M_PI))
                painter.drawText(-nWidth / 2, rText + nHeight - 8, self.mStrDown[i])
                painter.rotate(-90 * nWidth / (rText * self.M_PI))
            painter.restore()

            painter.save()
            if (self.m_bTextModeEn):
                iTotalWidth = fm.width(self.mStrLeft)
                painter.rotate(90 + 90 * iTotalWidth / (rText * self.M_PI))
                for i in range(len(self.mStrLeft)):
                    nWidth = fm.width(self.mStrLeft[i])
                    painter.rotate(-90 * nWidth / (rText * self.M_PI))
                    painter.drawText(-nWidth / 2, rText + nHeight - 8, self.mStrLeft[i])
                    painter.rotate(-90 * nWidth / (rText * self.M_PI))

            else:
                iTotalWidth = nHeight * len(self.mStrLeft)
                painter.rotate(90 * iTotalWidth / (rText * self.M_PI))
                for i in range(len(self.mStrLeft)):
                    painter.rotate(-90 * nHeight / (rText * self.M_PI))
                    painter.drawText(-rText - 10, nHeight / 2, self.mStrLeft[i])
                    painter.rotate(-90 * nHeight / (rText * self.M_PI))
            painter.restore()

    def addArc(self, x, y, startAngle, angleLength, color):
        rect = QRectF(-self.m_radius + x, -self.m_radius + y, self.m_radius * 2, self.m_radius * 2)
        path = QPainterPath()
        path.arcTo(rect, startAngle, angleLength)
        subPath = QPainterPath()
        subPath.addEllipse(rect.adjusted(self.m_arcLength, self.m_arcLength, -self.m_arcLength, -self.m_arcLength))
        path -= subPath
        self.m_arcPathList.append(path)
        radialGradient = QRadialGradient()
        radialGradient.setCenter(0, 0)
        radialGradient.setRadius(self.m_radius)
        radialGradient.setColorAt(0, color)
        radialGradient.setColorAt(1.0, color)
        self.m_colorList.append(radialGradient)

    def mousePressEvent(self, event):
        mousePressPoint = event.pos()
        translatePoint = mousePressPoint - QPoint(self.width() >> 1, self.height() >> 1)
        for i in range(len(self.m_arcPathList)):
            if (self.m_arcPathList[i].contains(translatePoint) or self.m_textPathList[i].contains(translatePoint)):
                self.m_pressIndex = i
                self.m_isMousePressed = True
                self.update()
                break

    def mouseReleaseEvent(self, event):
        if (self.m_isMousePressed):
            self.m_isMousePressed = False
            self.mCenterRound = QPoint(0, 0)
            self.mDegreePixmap_x = QPixmap(0, 0)
            self.mDegreePixmap_y = QPixmap(0, 0)
            self.update()

    def mouseMoveEvent(self, event):
        if (self.m_isMousePressed):
            point = event.pos() - QPoint(self.width() >> 1, self.height() >> 1)
            x = point.x()
            y = -point.y()
            if y >= 85:
                y = 85
            elif y <= -85:
                y = -85
            if x >= 85:
                x = 85
            elif x <= -85:
                x = -85
            if x * x + y * y > 85 * 85:
                x_y = abs(x) / abs(y)
                _y = 85 / math.sqrt(x_y * x_y + 1.0)
                _x = x_y * _y
                if y >= 0:
                    y = abs(_y)
                else:
                    y = -abs(_y)
                if x >= 0:
                    x = abs(_x)
                else:
                    x = -abs(_x)
            self.mCenterRound = QPoint(x, -y)

            # 通过分析x，y坐标，得到角度，值为0-360
            angle = self.analysisAngle(x, y)

            self.x = x
            self.y = y

            if angle >= 90 and angle <= 180:
                self.mCurWorkRegion = [self.QUADRANT_UP, self.QUADRANT_LEFT]
            elif angle > 0 and angle <= 90:
                self.mCurWorkRegion = [self.QUADRANT_UP, self.QUADRANT_RIGHT]
            elif angle > 180 and angle <= 270:
                self.mCurWorkRegion = [self.QUADRANT_DOWN, self.QUADRANT_LEFT]
            elif angle > 270 and angle < 360:
                self.mCurWorkRegion = [self.QUADRANT_DOWN, self.QUADRANT_RIGHT]
            self.mDegreePixmap_x = self.getPixmap(abs(x))
            self.mDegreePixmap_y = self.getPixmap(abs(y))
            self.update()

    def analysisAngle(self, x, y):
        angle = math.atan2(abs(y), abs(x)) / (2 * math.acos(-1)) * 360
        if (x < 0 and y > 0):
            angle = 180 - angle
        if (x < 0 and y < 0):
            angle += 180
        if (x > 0 and y < 0):
            angle = 360 - angle
        return angle

    def getPixmap(self, ping):
        return self.getSignalPixmap(QColor(0x5, 0x00c7, 0xc7), self.getLineNum(ping))

    def getColor(self, ping):
        if (ping <= 10):
            return QColor(0xea, 0x00, 0x00)
        elif (ping <= 20):
            return QColor(0xff, 0x00, 0x80)
        elif (ping <= 30):
            return QColor(0xe8, 0x00, 0xe8)
        elif (ping <= 40):
            return QColor(0xea, 0xc1, 0x00)
        elif (ping <= 50):
            return QColor(0xe1, 0xe1, 0x00)
        elif (ping <= 60):
            return QColor(0x9a, 0xff, 0x02)
        elif (ping <= 70):
            return QColor(0x00, 0xff, 0xff)
        elif (ping <= 80):
            return QColor(0x28, 0x94, 0xff)
        else:
            return QColor(0x6a, 0x6a, 0xff)

    def getLineNum(self, ping):
        if (ping <= 20):
            return 1
        elif (ping <= 40):
            return 2
        elif (ping <= 60):
            return 3
        elif (ping <= 80):
            return 4
        else:
            return 5

    def getSignalPixmap(self, color, linenum):

        pixmap = QPixmap(60, 30)
        pixmap.fill(QColor(255, 255, 255, 0))

        painter = QPainter(pixmap)
        painter.setRenderHint(QPainter.HighQualityAntialiasing, True)
        painter.setPen(QPen(color, 2, Qt.SolidLine, Qt.RoundCap, Qt.RoundJoin))
        i = 1
        xpos = 0
        while i <= linenum:
            painter.drawArc(30 - i * 6, 30 - i * 5, i * 12, i * 10, 53 * 16, 37 * 2 * 16)
            i += 1
            xpos += 1
        return pixmap

    def get_info(self):

        linear = round(self.setrange(self.y, 90) / 18, 2)
        angular = round(self.setrange(self.x, 90) / 18, 2)
        # angular = format(float(self.setrange(self.x, 90)) / float(18), '.2f')

        if -0.5 < linear < 0.5:
            linear = 0
        if -0.5 < angular < 0.5:
            angular = 0

        return linear, angular

    def setrange(self, x, number):
        if x > number or x < -number:
            x = number
        return x


if __name__ == '__main__':
    import sys
    from PyQt5.QtWidgets import QApplication

    app = QApplication(sys.argv)
    mainWindow = CustomButton()
    mainWindow.show()
    sys.exit(app.exec_())
