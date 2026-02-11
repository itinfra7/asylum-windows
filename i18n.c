#include <string.h>
#include "asylum.h"

extern asylum_options options;

typedef struct { const char* en; const char* de; const char* es; const char* ko; const char* zh; } tr_pair;

static const tr_pair translations[] = {
    { "Bonus 10000", "Bonus 10000", "Bono 10000", "보너스 10000", "奖励 10000" },
    { "Bonus 20000", "Bonus 20000", "Bono 20000", "보너스 20000", "奖励 20000" },
    { "Bonus 30000", "Bonus 30000", "Bono 30000", "보너스 30000", "奖励 30000" },
    { "Bonus 50000", "Bonus 50000", "Bono 50000", "보너스 50000", "奖励 50000" },
    { "Bonus 100000", "Bonus 100000", "Bono 100000", "보너스 100000", "奖励 100000" },
    { "- Game Interrupted -", "- Spiel unterbrochen -", "- Juego interrumpido -", "- 게임 중단 -", "- 游戏中断 -" },
    { "Please select action", "Bitte Aktion wählen", "Seleccione una acción", "작업을 선택하세요", "请选择操作" },
    { "ESC - Abandon game", "ESC - Spiel abbrechen", "ESC - Abandonar juego", "ESC - 게임 포기", "ESC - 放弃游戏" },
    { "Q    - lose this life", "Q    - Dieses Leben verlieren", "Q    - Perder esta vida", "Q    - 목숨 1개 잃기", "Q    - 失去一条命" },
    { "R    - Return to Game", "R    - Zurück zum Spiel", "R    - Volver al juego", "R    - 게임으로 돌아가기", "R    - 返回游戏" },
    { "O    - Alter Options", "O    - Optionen ändern", "O    - Cambiar opciones", "O    - 옵션 변경", "O    - 修改选项" },
    { "Options", "Optionen", "Opciones", "옵션", "选项" },
    { "1. Define Controls", "1. Steuerung festlegen", "1. Definir controles", "1. 조작 설정", "1. 设置操作" },
    { "2. Tune Game Options", "2. Spieloptionen anpassen", "2. Ajustar opciones", "2. 게임 옵션", "2. 调整游戏选项" },
    { "Fire - Play", "Feuer - Spielen", "Disparo - Jugar", "발사 키 - 시작", "开火 - 开始" },
    { "3. Choose Mental Zone", "3. Geisteszone wählen", "3. Elegir zona mental", "3. 정신 영역 선택", "3. 选择精神区域" },
    { "3. Save Position", "3. Position speichern", "3. Guardar posición", "3. 위치 저장", "3. 保存位置" },
    { "4. LANGUAGE-BETA", "4. LANGUAGE-BETA", "4. LANGUAGE-BETA", "4. LANGUAGE-BETA", "4. LANGUAGE-BETA" },
    { "Choose which", "Wähle aus", "Elige cuál", "선택하세요", "请选择" },
    { "mental zone", "Geisteszone", "zona mental", "정신 영역", "精神区域" },
    { "1. Ego", "1. Ego", "1. Ego", "1. 에고(Ego)", "1. 自我(Ego)" },
    { "2. Psyche", "2. Psyche", "2. Psique", "2. 프시케(Psyche)", "2. 心灵(Psyche)" },
    { "3. Id", "3. Es", "3. Ello", "3. 이드(Id)", "3. 本我(Id)" },
    { "4. Saved Game", "4. Gespeichertes Spiel", "4. Partida guardada", "4. 저장된 게임", "4. 已保存游戏" },
    { "To play the id", "Um das Es zu spielen", "Para jugar el Ello", "이드(Id)에 들어가려면", "要进入本我" },
    { "you need to complete", "musst du zuerst abschließen", "necesitas completar", "에고(Ego)를 완료해야", "你需要先完成" },
    { "the ego first.", "zuerst das Ego.", "primero el Ego.", "합니다.", "先完成自我。" },
    { "WELL DONE!", "GUT GEMACHT!", "¡BIEN HECHO!", "잘했어요!", "做得好！" },
    { "You have completed", "Du hast abgeschlossen", "Has completado", "완료했습니다", "你已完成" },
    { "The game!!!", "Das Spiel!!!", "¡El juego!!!", "게임을!!!", "整个游戏！！！" },
    { "This zone!", "Diese Zone!", "¡Esta zona!", "이 영역을!", "该区域！" },
    { "Controls", "Steuerung", "Controles", "조작", "操作" },
    { "1. Set Keys", "1. Tasten festlegen", "1. Configurar teclas", "1. 키 설정", "1. 设置按键" },
    { "1. Keyboard", "1. Tastatur", "1. Teclado", "1. 키보드", "1. 键盘" },
    { "2. Joystick", "2. Joystick", "2. Joystick", "2. 조이스틱", "2. 手柄" },
    { "Joystick", "Joystick", "Joystick", "조이스틱", "手柄" },
    { "Joystick Number", "Joystick-Nummer", "Número de joystick", "조이스틱 번호", "手柄编号" },
    { "Reminder", "Hinweis", "Recordatorio", "안내", "提示" },
    { "To jump, you can", "Zum Springen kannst du", "Para saltar, puedes", "점프는 다음 중 하나로", "跳跃可以" },
    { "1. Use Joystick Up", "1. Joystick nach oben", "1. Arriba en joystick", "1. 조이스틱 위", "1. 手柄上" },
    { "2. Use Fire Button 2", "2. Feuertaste 2", "2. Botón de disparo 2", "2. 발사 버튼 2", "2. 开火键2" },
    { "If you have one.", "Falls vorhanden.", "Si tienes uno.", "있을 경우", "如果有的话。" },
    { "3. Use The Up Key", "3. Pfeiltaste Hoch", "3. Tecla Arriba", "3. 위 키", "3. 上方向键" },
    { "Tune Game", "Spiel einstellen", "Ajustar juego", "게임 설정", "游戏设置" },
    { "1. Sound System", "1. Soundsystem", "1. Sistema de sonido", "1. 사운드 시스템", "1. 音效系统" },
    { "2. Sound Volume", "2. Lautstärke", "2. Volumen", "2. 사운드 볼륨", "2. 音量" },
    { "Sound Not", "Sound nicht", "Sonido no", "사운드", "声音不" },
    { "Available", "verfügbar", "disponible", "사용 불가", "可用" },
    { "3. Video System", "3. Videosystem", "3. Sistema de video", "3. 비디오 시스템", "3. 视频系统" },
    { "Tune Sound", "Sound einstellen", "Ajustar sonido", "사운드 설정", "声音设置" },
    { "and music", "und Musik", "y música", "및 음악", "与音乐" },
    { "ESC - Exit", "ESC - Beenden", "ESC - Salir", "ESC - 종료", "ESC - 退出" },
    { "Change volume", "Lautstärke ändern", "Cambiar volumen", "볼륨 변경", "调整音量" },
    { "1. Louder effects", "1. Effekte lauter", "1. Efectos más fuertes", "1. 효과음 크게", "1. 音效更大" },
    { "2. Quieter effects", "2. Effekte leiser", "2. Efectos más bajos", "2. 효과음 작게", "2. 音效更小" },
    { "3. Louder music", "3. Musik lauter", "3. Música más fuerte", "3. 음악 크게", "3. 音乐更大" },
    { "4. Quieter music", "4. Musik leiser", "4. Música más baja", "4. 음악 작게", "4. 音乐更小" },
    { "Tune Video", "Video einstellen", "Ajustar video", "비디오 설정", "视频设置" },
    { "-experimental-", "-experimentell-", "-experimental-", "-실험 기능-", "-实验功能-" },
    { "1. No Sound", "1. Kein Sound", "1. Sin sonido", "1. 무음", "1. 无音效" },
    { "2. 4 Channels", "2. 4 Kanäle", "2. 4 canales", "2. 4채널", "2. 4声道" },
    { "3. 4 Channels", "3. 4 Kanäle", "3. 4 canales", "3. 4채널", "3. 4声道" },
    { "4. 8 Channels", "4. 8 Kanäle", "4. 8 canales", "4. 8채널", "4. 8声道" },
    { "5. Normal Quality", "5. Normale Qualität", "5. Calidad normal", "5. 일반 품질", "5. 普通质量" },
    { "6. High Quality", "6. Hohe Qualität", "6. Alta calidad", "6. 고품질", "6. 高质量" },
    { "7. Overdrive", "7. Overdrive", "7. Overdrive", "7. 오버드라이브", "7. 过载" },
    { "5. Speaker on", "5. Lautsprecher an", "5. Altavoz activado", "5. 스피커 켜기", "5. 打开扬声器" },
    { "-5. Speaker on", "-5. Lautsprecher an", "-5. Altavoz activado", "-5. 스피커 켜기", "-5. 打开扬声器" },
    { "1. Full Screen", "1. Vollbild", "1. Pantalla completa", "1. 전체 화면", "1. 全屏" },
    { "2. Use OpenGL", "2. OpenGL verwenden", "2. Usar OpenGL", "2. OpenGL 사용", "2. 使用 OpenGL" },
    { "4. Half scale", "4. Halbe Skalierung", "4. Escala media", "4. 반배율", "4. 半倍缩放" },
    { "Digital Psychosis", "Digital Psychosis", "Digital Psychosis", "Digital Psychosis", "Digital Psychosis" },
    { "Presents", "präsentiert", "presenta", "제공", "呈现" },
    { "Young Sigmund has a", "Der junge Sigmund hat", "El joven Sigmund tiene", "어린 지그문트는", "年轻的西格蒙德有" },
    { "Few problems. Can", "ein paar Probleme. Kannst", "algunos problemas. ¿Puedes", "몇 가지 문제가 있습니다.", "一些问题。你能" },
    { "you help him find", "du ihm helfen, die", "ayudarlo a encontrar", "그가 비정상적인", "帮他找到" },
    { "the rogue brain cells", "abtrünnigen Gehirnzellen", "las neuronas rebeldes", "뇌세포를 찾아내", "失控的脑细胞" },
    { "in his mind and shut", "in seinem Geist zu finden und", "en su mente y", "멈출 수 있게", "在他脑中并" },
    { "Them down?", "sie zu stoppen?", "detenerlas?", "도와줄 수 있나요?", "阻止它们吗？" },
    { "PRESS SPACE", "LEERTASTE DRÜCKEN", "PULSA ESPACIO", "스페이스 키를 누르세요", "按空格键" },
    { "Cheat Mode!!!", "Cheat-Modus!!!", "¡Modo Trucos!!!", "치트 모드!!!", "作弊模式！！！" },
    { "F1, F2 Get Weapons", "F1, F2 Waffen erhalten", "F1, F2 obtienes armas", "F1, F2 무기 획득", "F1、F2 获得武器" },
    { "F3 - Restore Strength", "F3 - Stärke wiederherstellen", "F3 - Restaurar fuerza", "F3 - 체력 회복", "F3 - 恢复体力" },
    { "HAVE FUN !!!", "VIEL SPASS !!!", "¡DIVIÉRTETE!!!", "즐거운 시간 되세요!!!", "玩得开心！！！" },
    { "Please Wait", "Bitte warten", "Por favor espere", "잠시만 기다려 주세요", "请稍候" },
    { "Loading Game files", "Spieldateien werden geladen", "Cargando archivos del juego", "게임 파일 로딩 중", "正在加载游戏文件" },
    { "A file is missing.", "Eine Datei fehlt.", "Falta un archivo.", "파일이 없습니다.", "缺少文件。" },
    { "It cannot be loaded", "Sie kann nicht geladen werden", "No se puede cargar", "불러올 수 없습니다", "无法加载" },
    { "Unable to Load File", "Datei kann nicht geladen werden", "No se pudo cargar el archivo", "파일을 불러올 수 없음", "无法加载文件" },
    { "Please Check Disc", "Bitte Datenträger prüfen", "Compruebe el disco", "디스크를 확인하세요", "请检查光盘" },
    { "A game file could not", "Eine Spieldatei konnte", "Un archivo del juego no pudo", "게임 파일을", "游戏文件无法" },
    { "be loaded. Program", "nicht geladen werden. Programm", "cargarse. El programa", "불러올 수 없습니다.", "加载，程序" },
    { "Must exit now.", "muss jetzt beendet werden.", "debe salir ahora.", "프로그램을 종료합니다.", "必须退出。" },
    { "The level cannot be", "Das Level kann nicht", "El nivel no puede", "레벨을", "关卡无法" },
    { "Loaded. Please check", "geladen werden. Bitte prüfe", "cargarse. Por favor revisa", "불러올 수 없습니다.", "加载。请检查" },
    { "the disc, or press", "den Datenträger oder drücke", "el disco o pulsa", "디스크를 확인하거나", "光盘，或按" },
    { "escape to end game.", "ESC zum Beenden.", "ESC para terminar.", "ESC로 종료하세요.", "ESC 结束游戏。" },
    { "There is not enough", "Es gibt nicht genug", "No hay suficiente", "메모리가 부족합니다.", "没有足够的" },
    { "memory available to", "verfügbaren Speicher, um", "memoria disponible para", "게임 파일을", "可用内存来" },
    { "load the game files.", "die Spieldateien zu laden.", "cargar los archivos del juego.", "불러올 수 없습니다.", "加载游戏文件。" },
    { "RET - Try Again", "ENTER - Erneut", "ENTRAR - Reintentar", "엔터 키 - 다시 시도", "回车 - 重试" },
    { "ESC - Abandon", "ESC - Abbrechen", "ESC - Abandonar", "ESC - 포기", "ESC - 放弃" },
    { "RET - OK", "ENTER - OK", "ENTRAR - OK", "엔터 키 - 확인", "回车 - 确定" },
    { "press fire", "Feuer drücken", "pulsa disparo", "발사 키를 누르세요", "按下开火" },
    { "Zone High Scores", "Zonen-Highscores", "Puntuaciones de la zona", "영역 최고 점수", "区域最高分" },
    { "A potion and Skull!", "Ein Trank und Schädel!", "¡Una poción y un cráneo!", "포션과 해골!", "药水和骷髅！" },
    { "Rise from the dead!", "Steh von den Toten auf!", "¡Resucita!", "부활하라!", "从死亡中复活！" },
    { "Let's Go!", "Los geht's!", "¡Vamos!", "시작!", "出发！" },
    { "- Snuffed It! -", "- Ausgeschieden! -", "- ¡Has muerto! -", "- 사망 -", "- 你死了 -" },
    { "-  GAME OVER  -", "-  SPIEL VORBEI  -", "-  FIN DEL JUEGO  -", "- 게임 오버 -", "-  游戏结束  -" },
    { "Can't see a joystick!", "Joystick nicht gefunden!", "¡No se detecta joystick!", "조이스틱을 찾을 수 없음!", "未检测到手柄！" },
    { "Press Key For Left", "Taste für Links drücken", "Pulse tecla para Izquierda", "왼쪽 키를 누르세요", "按下左键" },
    { "Press Key For Right", "Taste für Rechts drücken", "Pulse tecla para Derecha", "오른쪽 키를 누르세요", "按下右键" },
    { "Press Key For Down", "Taste für Unten drücken", "Pulse tecla para Abajo", "아래 키를 누르세요", "按下下键" },
    { "Press Key to Fire", "Taste zum Feuern drücken", "Pulse tecla de Disparo", "발사 키를 누르세요", "按下开火键" },
    { "Press Key to Jump", "Taste zum Springen drücken", "Pulse tecla para Saltar", "점프 키를 누르세요", "按下跳跃键" },
    { "LANGUAGE-BETA", "LANGUAGE-BETA", "LANGUAGE-BETA", "LANGUAGE-BETA", "LANGUAGE-BETA" },
    { "1. ENGLISH", "1. ENGLISH", "1. ENGLISH", "1. ENGLISH", "1. ENGLISH" },
    { "2. DEUTSCH", "2. DEUTSCH", "2. DEUTSCH", "2. DEUTSCH", "2. DEUTSCH" },
    { "3. ESPAÑOL", "3. ESPAÑOL", "3. ESPAÑOL", "3. ESPAÑOL", "3. ESPAÑOL" },
    { "4. 한국어", "4. 한국어", "4. 한국어", "4. 한국어", "4. 한국어" },
    { "5. 简体中文", "5. 简体中文", "5. 简体中文", "5. 简体中文", "5. 简体中文" },
    { "Standard Mini-Gun", "Standard-Minigun", "Minigun estándar", "표준 미니건", "标准迷你枪" },
    { "Mini-Gun with spray", "Minigun mit Streuung", "Minigun con dispersión", "분사형 미니건", "散射迷你枪" },
    { "Five Stream Gun", "Fünfstrahl-Kanone", "Arma de cinco rayos", "5연사 건", "五连射枪" },
    { "Fast 5 way - zap those nasties!", "Schnell 5-fach – grill sie!", "5 vías rápido: ¡fríelos!", "쾌속 5방향 - 싹 다 지져버려!", "快速五向 - 电翻它们！" },
    { "A weird one!", "Ein seltsames Ding!", "¡Una rara!", "이건 좀 기묘한데?!", "很怪的一把！" },
    { "Three Way Blitzer", "Drei-Wege-Blitzer", "Blitzer de tres vías", "3방향 블리처", "三向闪击枪" },
    { "Blitzing Five Way - Lets Party", "Fünf-Wege-Blitz – Party!", "Blitz de cinco vías: ¡fiesta!", "5방향 블리처 - 파티다!", "五向闪击 - 开趴！" },
    { "MegaBlam 5000 Mini-Gun!!!!", "MegaBlam 5000 Minigun!!!!", "MegaBlam 5000 Minigun!!!!", "메가블램 5000 미니건!!!!", "MegaBlam 5000 迷你枪!!!!" },
    { "Standard Rocket Launcher", "Standard-Raketenwerfer", "Lanzacohetes estándar", "표준 로켓 런처", "标准火箭发射器" },
    { "Twin Rocket Launcher", "Doppel-Raketenwerfer", "Lanzacohetes doble", "트윈 로켓 런처", "双联火箭发射器" },
    { "Quad Launcher - Open Fire!", "Vierfachwerfer – Feuer frei!", "Lanzador cuádruple: ¡fuego!", "쿼드 런처 - 일제 사격!", "四联发射器 - 开火！" },
    { "Launcher with starburst", "Werfer mit Sternenexplosion", "Lanzador con estallido", "스타버스트 런처", "星爆发射器" },
    { "Twin rockets with starburst - let's see some fireworks!", "Doppelraketen mit Sternenexplosion – Feuerwerk!", "Cohetes dobles con estallido: ¡fuegos!", "트윈 스타버스트 로켓 - 불꽃놀이!", "双联星爆火箭 - 烟花吧！" },
    { "Quad Launcher with starburst! Arrgghhhh!!!!", "Vierfachwerfer mit Sternenexplosion! Arrgghhhh!!!!", "Lanzador cuádruple con estallido ¡Arrgghhhh!!!!", "쿼드 스타버스트 런처! 으아아아!!!!", "四联星爆发射器！啊啊啊!!!!" },
    { "A Pot Pourri Rocket Launcher - mix and match!", "Potpourri-Raketenwerfer – mix & match!", "Lanzacohetes variado: ¡combina!", "포푸리 로켓 런처 - 골라 쏘는 재미!", "拼盘火箭发射器 - 随意搭配！" },
    { "MegaBlam Rocket Launcher!!!!  Six Shots Only!", "MegaBlam-Raketenwerfer!!!! Nur 6 Schüsse!", "Lanzacohetes MegaBlam!!!! ¡Solo 6 disparos!", "메가블램 로켓 런처!!!! 딱 6발뿐!", "MegaBlam 火箭发射器!!!! 仅6发！" }
};

const char* tr(const char* a)
{
    if (options.language == 0 || a == NULL) return a;
    static char buf[256];
    unsigned char prefix = (unsigned char)a[0];
    if (prefix == 16 || prefix == 17)
    {
        const char* base = a + 1;
        const char* out = base;
        for (unsigned int i = 0; i < sizeof(translations)/sizeof(translations[0]); i++)
        {
            if (strcmp(base, translations[i].en) == 0)
            {
                switch (options.language)
                {
                case 1: out = translations[i].de; break;
                case 2: out = translations[i].es; break;
                case 3: out = translations[i].ko; break;
                case 4: out = translations[i].zh; break;
                default: out = base; break;
                }
                break;
            }
        }
        buf[0] = (char)prefix;
        strncpy(buf + 1, out, sizeof(buf) - 2);
        buf[sizeof(buf) - 1] = 0;
        return buf;
    }
    for (unsigned int i = 0; i < sizeof(translations)/sizeof(translations[0]); i++)
    {
        if (strcmp(a, translations[i].en) == 0)
        {
            switch (options.language)
            {
            case 1: return translations[i].de;
            case 2: return translations[i].es;
            case 3: return translations[i].ko;
            case 4: return translations[i].zh;
            default: return a;
            }
        }
    }
    return a;
}
