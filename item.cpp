#include "item.h"

Item::Item() {}

Item::~Item() {}


QString Item::get_name() {
    return name;
}
QString Item::get_id() {
    return id;
}

void Item::set_name(QString str) {
    name = str;
}

void Item::set_id(QString str) {
    id = str;
}
//функция для получения рандомного идентификатора, тип QString выбран для того, чтобы было ровно 8 цифр
QString Item::rand_id() {
    QRandomGenerator *rand = QRandomGenerator::global();
    for (int i=0; i < 10; i++){
            rand->bounded(0,9);
    }
    QString digits[10] = { "0","1","2","3","4","5","6","7","8","9"};
    QString res =   digits[rand->bounded(0,9)] + digits[rand->bounded(0,9)]+
                    digits[rand->bounded(0,9)] + digits[rand->bounded(0,9)]+
                    digits[rand->bounded(0,9)] + digits[rand->bounded(0,9)]+
                    digits[rand->bounded(0,9)] + digits[rand->bounded(0,9)];
    return res;
}
//массив с названиями оборудования
QString names[128] = {  "IP-телефон Avaya 1608", "IP-телефон Cisco CP-6901",
                        "IP-телефон Grandstream GXP2100", "IP-телефон Yealink SIP-T27G",
                        "Абонентский терминал InfiNet Smc/54.300.2x63.2x21-ODU", "Абонентский терминал GPON Dasan H645B",
                        "Адаптер POE Ubiquiti POE-24-24W", "Адаптер SNMP Powercom NetAgent II (BT506)",
                        "Аккумуляторная батарея Delta HRL 12-34W (12V 9Ah)", "Блок питания Juniper PWR-MX480-2400-DC-S",
                        "Блок питания Vermax-PS2U/AC", "Блок 8 розеток 19\"",
                        "Брандмауэр Cisco ASA 5525-X", "Видеокамера OMNY M64E 2812",
                        "Видеокамера Satvision SVI-D222-N", "Внешний радиоблок Ceragon IP-20C-E-18-L-H-ESS",
                        "Внешний радиоблок Siklu EH-2500FX-ODU-L-EXT", "Внутрений блок Ceragon FibeAir IP10-N-N",
                        "Делитель оптический 2*16", "Делитель оптический 1*4",
                        "ИБП APC Smart-UPS XL 2200 (SUA2200XLI)", "ИБП Inelt Monolith II 3000RMLT",
                        "ИБП SNR-UPS-ONRM-1500-X36", "Инжектор PoE Cambium ePMP 1000",
                        "Инжектор POE Powertone PI-600-1", "Кабель FTP 4 пары, кат. 5, для внешней прокладки",
                        "Кабель ВВГнг 3*10", "Кабель коаксиальный типа RG-11",
                        "Кабель оптический 128-волоконный 15 кН", "Кабель оптический 4-волоконный 2,7 кН, для внутренней прокладки",
                        "Кабельная сборка (RP-SMA male-RP-SMA female), 2м", "Коммутатор D-Link DGS-1008D",
                        "Коммутатор Allied Telesis AT-8000S/48", "Коммутатор Beward STW-16P8",
                        "Коммутатор Cisco Linksys SRW2016", "Коммутатор Cisco WS-C2950G-24-EI",
                        "Коммутатор Cisco WS-C2960S-48FPS-L", "Коммутатор Cisco WS-C2960-48PST-L",
                        "Коммутатор Cisco WS-C3524-XL-EN", "Коммутатор Cisco WS-C3750G-48TS-S",
                        "Коммутатор Cisco WS-C3560G-48PS-S", "Коммутатор TP-Link T2600G-28TS V4 DC",
                        "Коммутатор D-Link DES-1228ME", "Коммутатор D-Link DES-3200-52",
                        "Коммутатор D-Link DGS-1210-28XS/ME/B1", "Коммутатор D-Link DGS-3120-24TC",
                        "Коммутатор D-Link DXS-1210-12SC", "Коммутатор Eltex MES2324B",
                        "Коммутатор Eltex MES5248", "Коммутатор Extreme Summit X450-24x",
                        "Коммутатор Extreme Summit X670V-48x", "Коммутатор HP 1920-48G",
                        "Коммутатор Huawei S5320-28P-LI-AC", "Коммутатор Huawei S6320-54C-EI-48S-DC",
                        "Кросс оптический КРС-144-LC", "Кросс оптический ШКОН-4-SC",
                        "Маршрутизатор Cisco 2610", "Маршрутизатор Cisco 2811",
                        "Маршрутизатор Cisco 7603-S", "Маршрутизатор Ubiquiti EdgePoint-R8",
                        "Маршрутизатор D-Link DIR-100", "Маршрутизатор Eltex ESR-100",
                        "Маршрутизатор Juniper SRX210B", "Маршрутизатор Juniper MX150-R",
                        "Маршрутизатор Mikrotik hEX RB750Gr3", "Маршрутизатор Mikrotik CCR1009-8G-1S",
                        "Модем CDMA Skylink Airplus MCD-800", "Модем D-Link DSL-2500U",
                        "Модем GSM Teleofis RX 101-R4", "Модем Zyxel P-792H",
                        "Модуль Cisco VWIC2-1MFT-G703", "Модуль Juniper ES2-4GS1-MOD",
                        "Модуль компенсации дисперсии Huawei DCM-F (120км)", "Модуль питания Mean Well RCP-1000-48",
                        "Модуль управления Huawei TMF1SCC OSN9800", "Модуль-мультиплексор Qtech QBM-P2M1D6R1 v3",
                        "Мультиплексор ECI RBM 2004+E", "Мультиплексор SDH Huawei Optix 155/622H",
                        "Муфта оптическая МТОК-6/108", "Муфта-кросс оптическая 20/20-SC, 1 делитель 1*8",
                        "Оконечная станция InfiNet Mmxt/6.300.2x200.2x24-ODU", "Оконечная станция Ubiquiti AirFiber 24 HD",
                        "Патч-корд RJ45-RJ45 1,0 м", "Передатчик оптический Volius VS-5711",
                        "Переключатель KVM TRENDnet TK-EX2", "Переходник Ubiquiti airFiber Antenna Conversion Kit",
                        "Плата Alcatel-Lucent LKA1D ADM 16/1", "Плата Avaya TN771DP",
                        "Плата Ericsson ROJ 207 030/2 (RPBI-S)", "Плата Huawei FVPD (UMG8900)",
                        "Плата Nortel NTDK20KA", "Плата Samsung KP70D-BRG2/RUA",
                        "Преобразователь MOXA NPort 5630-16", "Приемник оптический FOROtel SHO 212A",
                        "Приемник оптический Vector Lambda Pro 51", "Приемник оптический Volius VS5793",
                        "Приемник цифровой PBI DCH-3100P-10S2", "Радиоблок Ceragon IP-20S-13-266A-5W8-TL-ESS",
                        "Радиоблок DragonWave Harmony Enhanced T562RL13B01S0.00", "Рефлектометр оптический KIWI-7212",
                        "Радиоблок E-Band E-Link Eagle EP Low", "Радиоблок Intracom UltraLink-FX80 (TDD)",
                        "Радиомост Ubiquiti GigaBeam Plus 60 GHz", "Система Wi-Fi Mesh Tenda MW3-3",
                        "Сектор базовой станции Cambium PMP-450m (Medusa)", "Сектор базовой станции InfiNet O/5.3-18-ODU",
                        "Система эл/питания Eltek FlatPack 2 48V 16kw 19\" 6U", "Система эл/питания Delta DPS 1600-48-4 6,4kw",
                        "Стойка каркасная(двухрамная) 19\" 54U", "Стойка 19\" 42U",
                        "Термошкаф ТШ-2", "Точка доступа MikroTik mANTBox 15s (RB921GS-5HPacD-15S)",
                        "Точка доступа Mikrotik SXT SA5 (RBSXTG-5HPnD-SAr2)", "Точка доступа Wi-Fi D-Link DAP-3690",
                        "Точка доступа Wi-Fi Huawei AP7050DE", "Точка доступа Wi-Fi Ruckus ZoneFlex 7762",
                        "Точка доступа Wi-Fi Ubiquiti UniFi AP Outdoor (UAP-Outdoor5)", "Усилитель UpNet EA62129 (18дБм*8п) 2AC",
                        "Усилитель оптический Huawei TN12OAU101 (20-31 дБ)", "Усилитель оптический TVBS EDFA1550HQ-33",
                        "Усилитель оптический Volius VS-5752", "Усилитель оптический Тарос EAU-800/16-C2-220-II",
                        "Шкаф напольный 19\" 24U 600*900", "Шкаф напольный 19\" 42U 800*1000",
                        "Шлюз D-Link DVG-2016S", "Шлюз TDM Зелакс (MM-116M-8E1-T-UPR)",
                        "Шнур оптический монтажный SM-3.0-SC/UPC-01.0", "Ящик телекоммуникационный пластиковый"};

//функция для получения размера массива с оборудованием, размер вектора изначально будет такой же
int Item::get_size() {
    return (sizeof(names) / sizeof(names[0]));
}
//функция для создания вектора для хранения Item'ов
QVector<Item> Item::set_vector_of_items() {
    QVector<Item> vectorItems;
    Item temp;
    for (int i = 0; i < get_size(); i++) {              //сначала инициализируем пустыми объектами
        vectorItems.append(temp);
    }
    for (int i = 0; i < vectorItems.size(); i++) {      //далее заполняем значениями
        vectorItems[i].name = names[i];
        vectorItems[i].id = rand_id();
    }
    return vectorItems;
}
//функция для получения рандомного количества в городах, зависит от сида, в его роли выступит номер строки таблицы
int Item::get_rand_count(int seed, int min, int max) {
    qsrand(seed);
    return (qrand() % ((max + 1) - min) + min);
}

