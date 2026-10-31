// #include <stdio.h>
// #include <ctype.h>


// Exercise One: Mini Port Scanner
/*
التمرين الأول: ماسح المنافذ المصغر (Mini Port Scanner)
المطلوب:
    قم بتعريف مصفوفة أعداد صحيحة (int) تحتوي على 4 أرقام لمنافذ شبكة (Ports). اختر الأرقام التالية: 21, 22, 80, 443.
    استخدم حلقة تكرار من نوع for للمرور على جميع عناصر هذه المصفوفة واحدًا تلو الآخر.
    داخل الحلقة: استخدم جملة شرطية (if / else if / else) لتقييم رقم المنفذ الحالي:
        إذا كان المنفذ 80 أو 443، اطبع رسالة: "Port [رقم المنفذ] is for Web Traffic".
        إذا كان المنفذ 22، اطبع رسالة: "Port 22 is for Secure Shell".
        أي منفذ آخر، اطبع رسالة: "Port [رقم المنفذ] is an Unknown Service".
تلميح:
تذكر كيف كان المهندس يحدد بداية الحلقة ونهايتها في ملف loops.c للوصول إلى عناصر المصفوفة باستخدام الفهرس (Index).


int main()
{
    int ports[4]={21, 22, 80, 443};
    for (int i = 0; i <= 3; i++)
    {
        if(ports[i]== 80 || ports[i] == 443){
            printf("is for Web Traffic -> %d \n",ports[i]);
        }
        else if(ports[i] == 22){
            printf("Port 22 is for Secure Shell -> %d \n",ports[i]);
        }
        else{
            printf("is an Unknown Service -> %d \n",ports[i]);
        }
    }
    
    return 0;
}
*/

// Exercise Tow : Password Digit Counter
/*
التمرين الثاني: عدّاد الأرقام في كلمة المرور (Password Digit Counter)
في هذا التمرين، سنقوم بتنظيم الكود الخاص بنا باستخدام الدوال (Functions) بدلاً من كتابة كل شيء
داخل `main`، وسنستخدم مكتبة `<ctype.h>` التي شرحها المهندس في ملفي `exercises.c` و `password_strength_checker.c`.
المطلوب كتابة برنامج ينفذ الآتي:
1. استدعِ المكتبات اللازمة، وتأكد من إضافة `<ctype.h>` لتتمكن من استخدام دالة `isdigit`.
2. قبل دالة `main`: قم بالإعلان عن دالة جديدة (Function Declaration) وسمّها `count_digits`.
    - هذه الدالة يجب أن تُرجع قيمة من نوع عدد صحيح (`int`).
    - يجب أن تستقبل مُعاملًا واحدًا (Parameter) عبارة عن سلسلة نصية (مصفوفة رموز `char[]` أو مؤشر للنص).
3. داخل الدالة `count_digits`:
    - عرّف متغيرًا ليكون بمثابة "عدّاد" (Counter) وابدأ قيمته بصفر.
    - استخدم حلقة `for` مع دالة `strlen` للمرور على كل حرف من أحرف السلسلة النصية.
    - داخل الحلقة، استخدم جملة `if` مع دالة `isdigit` لفحص الحرف الحالي. إذا كان الحرف عبارة عن رقم، قم بزيادة العدّاد بمقدار 1.
    - بعد انتهاء الحلقة، استخدم أمر `return` لإرجاع قيمة العدّاد النهائي.
4. داخل دالة `main`:
    - عرّف مصفوفة رموز لاستقبال كلمة المرور من المستخدم بحجم 50 حرفًا.
    - اطلب من المستخدم إدخال كلمة المرور باستخدام `fgets`.
    - قم باستدعاء الدالة `count_digits` ومرر لها كلمة المرور التي أدخلها المستخدم، وخزّن النتيجة في متغير جديد.
    - اطبع النتيجة للمستخدم (مثال: "Your password contains 3 digits").

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int count_digits(const char passowrd){

    int counter = 0;
    int length_password = strlen(passowrd);
    int actuale_password = length_password -1;
    for(size_t i=0; i < actuale_password; i++){
        if (isdigit(passowrd[i]))
        {
            counter++;
        }   
    }
    return counter;
}

int main()
{
    char passowrd[50];
    printf("Enter Your Passowrd: ");
    fgets(passowrd,sizeof(passowrd),stdin);

    count_digits(passowrd);

    int result = count_digits(passowrd);
    printf("Your password contains %d digits\n",result);
    return 0;
}
*/

// Exercise Four: Failed Login Simulator.
/*
التمرين الثالث: محاكي محاولات الدخول الفاشلة (Failed Login Simulator)
في هذا التمرين، سنستخدم المؤشرات (Pointers) لتعديل قيمة متغير موجود داخل `main` من خلال دالة خارجية، وسنستخدم حلقة `while` لتكرار العملية.
المطلوب كتابة برنامج ينفذ الآتي:
1. قبل دالة `main`: قم بالإعلان عن دالة اسمها `record_failure`.
    - هذه الدالة لا تُرجع أي قيمة (استخدم نوع الإرجاع `void`).
    - تستقبل مُعاملًا واحدًا عبارة عن مؤشر لعدد صحيح (`int attempts_ptr`).
    - داخل الدالة: استخدم معامل التوجيه (`*`) لزيادة القيمة الموجودة في هذا العنوان بمقدار
    1. (تذكر كيف قام المهندس بتغيير قيمة الباسوورد عبر المؤشر في التمرين الرابع من ملف الذاكرة).
2. داخل دالة `main`:
    - عرّف متغيرًا عاديًا من نوع عدد صحيح باسم `failed_attempts` وأعطه القيمة 0.
    - قم بإنشاء حلقة تكرار من نوع `while`. شرط الحلقة: أن تستمر في العمل طالما أن `failed_attempts` أقل من 3.
    - داخل حلقة `while`:
        - اطبع رسالة تحذيرية: "Login Failed! Recording attempt...".
        - قم باستدعاء الدالة `record_failure`. ولأن الدالة تتطلب مؤشرًا، يجب أن تمرر لها عنوان الذاكرة الخاص بالمتغير 
        `failed_attempts` باستخدام معامل العنوان (`&`).
    - خارج الحلقة (بعد انتهائها): اطبع رسالة: "Account Locked. Maximum attempts reached!".


#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

void record_failure(int *attempts_ptr){
    
    *attempts_ptr =2;
}
int main()
{
    int failed_attempts = 0;
    while (failed_attempts < 3)
    {
        printf("Login Failed! Recording attempt...\n");
        record_failure(&failed_attempts);
    }
    printf("Account Locked. Maximum attempts reached!\n");
    
    return 0;
}
*/

// Exercise Five: Weak Password Defender

/*
التمرين الخامس: نظام الحماية من كلمات المرور الضعيفة (Weak Password Defender)
المطلوب كتابة برنامج ينفذ الآتي:
    خارج main: قم بكتابة دالة تقييم اسمها evaluate_password.
        تستقبل الدالة السلسلة النصية (كلمة المرور).
        تُرجع الدالة عددًا صحيحًا (Score) يمثل قوة الكلمة (من 0 إلى 2).
        تبدأ قيمة الـ Score بصفر. تزيد بمقدار 1 إذا كان طول الكلمة الفعلي (بدون سطر الإدخال الجديد) 8 أحرف أو أكثر. وتزيد بمقدار 1 
        إضافي إذا كانت الكلمة تحتوي على رقم واحد على الأقل (استخدم حلقة تكرار ودالة فحص الأرقام).
        في النهاية، تُرجع الدالة هذه النتيجة (Score).
    داخل main:
        لديك نظام يعطي المستخدم 3 محاولات كحد أقصى لإدخال كلمة مرور قوية (تحصل على تقييم 2 من 2).
        اطلب من المستخدم إدخال كلمة المرور.
        استدعِ دالة التقييم وافحص النتيجة.
        إذا كانت النتيجة 2: اطبع رسالة "Password Accepted. Access Granted!"، وأوقف حلقة المحاولات فورًا
        (تلميح: يمكنك تغيير شرط الحلقة أو استخدام أمر الخروج من الحلقة).
        إذا كانت النتيجة أقل من 2: اطبع رسالة "Weak Password!"، واعرض للمستخدم عدد المحاولات المتبقية له.
        إذا استنفد المستخدم محاولاته الثلاث دون إدخال كلمة مرور قوية، اطبع تنبيهًا أمنيًا: "ALERT: Account Locked Due to Weak Passwords!".

#include <stdio.h>
#include <string.h>
#include <ctype.h>
int evaluate_password(const char password[]){
    int score = 0;
    int length_password = strlen(password);
    int actual_length = length_password - 1;
    if (actual_length >= 8) {
        score++;
    }
    for (int i = 0; i < length_password; i++) {
        if (isdigit(password[i])) {
            score++;
            break;
        }
    }
    return score;
}

int main()
{
    char password[20];
    int attempts = 3;
    int score;
    while (attempts > 0) {
        printf("Enter password: ");
        fgets(password, sizeof(password), stdin);
        score = evaluate_password(password);
        if (score == 2) {
            printf("Password Accepted. Access Granted!\n");
            break;
        } else {
            printf("Weak Password!\n");
            attempts--;
            if (attempts > 0) {
                printf("You have %d attempts remaining.\n", attempts);
            }
        }
    }
    if (attempts == 0) {
        printf("ALERT: Account Locked Due to Weak Passwords!\n");
    }
    return 0;
}
*/

// Exercise Six: Log Entry Risk Evaluator
/*
 التمرين السادس : مراقب الأنشطة المشبوهة (Suspicious Activity Monitor)
هذا التمرين مشابه لفكرة مقياس قوة كلمة المرور، لكننا سنطبقه على سيناريو تحليل سجلات النظام (Log Analysis)، للبحث عن مؤشرات الاختراق (IOCs).
المطلوب كتابة برنامج ينفذ الآتي:
1. خارج `main`: قم بإنشاء دالة باسم `evaluate_risk`.
    - تستقبل الدالة سلسلة نصية تمثل السجل (مثلًا: `const char log_entry[]`).
    - تُرجع الدالة عددًا صحيحًا `int` يمثل "مستوى الخطر" (Risk Level).
    - داخل الدالة:
        - أنشئ متغيرًا للعداد `risk` واجعل قيمته الابتدائية صفرًا.
        - احسب الطول الفعلي للنص (لا تنسَ خصم السطر الجديد `\n`).
        - الشرط الأول: إذا كان الطول الفعلي للسجل أقل من 5 أحرف (إشارة إلى محاولة فحص منافذ سريعة أو Ping)، قم بزيادة `risk` بمقدار 1.
        - الشرط الثاني: استخدم حلقة `for` للمرور على أحرف السلسلة. ابحث عن الرمز `'$'` (والذي قد يشير إلى محاولة وصول لبيانات مالية). إذا وجدت هذا الرمز، زِد قيمة `risk` بمقدار 1، وأوقف حلقة البحث فورًا (`break`).
        - أرجع القيمة النهائية للمتغير `risk`.
2. داخل `main`:
    - صمم نظامًا يعطي المستخدم 3 محاولات كحد أقصى لإدخال سجل نظيف.
    - استخدم حلقة `while` لطلب إدخال السجل `Log Entry` واستقباله عبر `fgets`.
    - مرر السجل لدالة `evaluate_risk` واستقبل مستوى الخطر.
    - قيّم مستوى الخطر باستخدام `if / else if / else`:
        - إذا كان الخطر 0: اطبع "Log is clean. System Normal."، واخرج من الحلقة فورًا (انتهى الفحص بنجاح).
        - إذا كان الخطر 2: اطبع تنبيهًا شديدًا "CRITICAL: Malicious log detected!"، واخرج من الحلقة فورًا (لأن الخطر عالٍ جدًا ولا يسمح بمحاولات أخرى).
        - إذا كان الخطر 1: اطبع "Warning: Unusual log."، قم بإنقاص عدد المحاولات، واطبع للمستخدم عدد المحاولات المتبقية.
    - بعد انتهاء الحلقة، استخدم شرطًا لفحص ما إذا كانت المحاولات قد نفدت (تساوي 0). إذا كان الأمر كذلك، اطبع: "System Suspended for Investigation."


#include <stdio.h>
#include <ctype.h>
#include <string.h>

int evaluate_risk(const char log_entry[]){
	int risk = 0;
	int length_log = strlen(log_entry);
	int actual_length = length_log -1;
	if(actual_length < 5 ){
		risk ++;
	}
	for(int i=0; i < length_log ; i++ ){
		if(log_entry[i] =='$'){
			risk++;
			break;
		}
	}
	
	return risk;
}

int main(){
	
	char log_entry[15];
	int attempts =3;
	int risk;
	while(attempts	> 0 ){
		printf("Enter log entery: ");
		fgets(log_entry,sizeof(log_entry),stdin);
		risk =evaluate_risk(log_entry);
		if(risk	== 0){
			printf("Log is clean. System Normal");
			break;
		}
		if(risk	== 2){
			printf("CRITICAL: Malicious log detected!");
			break;
		}
		if(risk == 1){
			printf("Warning: Unusual log.");
			attempts --;
			if (attempts > 0) {
                printf("You have %d attempts remaining.\n", attempts);
            }
		}
	}
	if(attempts	==0 ){
		printf("System Suspended for Investigation.");
	}
	
	return 0;
}
*/

// Exercise Seven: IP Anonymizer
/*
التمرين السابع: مُخفي عناوين الشبكة (IP Anonymizer)
في مجال الأمن السيبراني وحماية الخصوصية، نحتاج غالباً إلى إخفاء الجزء الأخير من عنوان الـ 
IP (مثل تحويل 192.168.1.15 إلى 192.168.0.0). سنقوم ببناء دالة تفعل ذلك بالاعتماد
على حقيقة أن المصفوفات تُعامل معاملة المؤشرات (Pointers) عند تمريرها للدوال.
المطلوب كتابة برنامج ينفذ الآتي:
    خارج main: قم بإنشاء دالة باسم anonymize_ip.
        هذه الدالة لا تُرجع شيئاً (void).
        تستقبل مُعاملًا واحدًا عبارة عن مصفوفة أعداد صحيحة (int ip[] أو int *ip كلاهما يؤدي نفس الغرض).
        داخل الدالة: استخدم حلقة for تبدأ من الفهرس (Index) رقم 2 وتنتهي عند الفهرس رقم 3
        (أي أنها ستستهدف العنصرين الأخيرين فقط من المصفوفة ذات الـ 4 عناصر).
        داخل الحلقة: اجعل قيمة العنصر الحالي تساوي 0.
    داخل main:
        عرّف مصفوفة أعداد صحيحة int مكوّنة من 4 عناصر تمثل عنوان IP. أعطها القيم التالية: {192, 168, 1, 15}.
        استخدم حلقة for لطباعة هذا العنوان الأصلي. (ملاحظة لتجميل الطباعة: يمكنك طباعة الرقم متبوعاً بنقطة .
        ، وفي العنصر الأخير اطبع الرقم متبوعاً بسطر جديد \n بدلاً من النقطة باستخدام جملة شرطية if).
        استدعِ الدالة anonymize_ip ومرر لها مصفوفة الـ IP. (تذكر: عند تمرير مصفوفة، 
        أنت تمرر عنوانها في الذاكرة ضمناً، لذا ستتعدل القيم الأصلية مباشرة).
        استخدم حلقة for أخرى لطباعة العنوان بعد التعديل (المتوقع أن يطبع 192.168.0.0).


#include <stdio.h>
#include <ctype.h>
#include <string.h>

void anonymize_ip(int ip[]){

	for(int i =2; i < 4; i++){
		ip[i] = 0;
	}
}
int main(){
	
	int ip[4]={192, 168, 1, 15};
	printf("Original IP: ");
	for(int c =0; c < 4; c++){
		if(c ==3){
			printf("%d\n",ip[c]);
		}
		else{
			printf("%d.",ip[c]);
		}
	}
	anonymize_ip(ip);
	printf("Address: ");
	for(int c =0; c < 4; c++){
		if(c ==3){
			printf("%d\n",ip[c]);
		}
		else{
			printf("%d.",ip[c]);
		}
	}
	return 0;
}

*/


// Exercise Eight: Mini Firewall
/*
 التمرين الإضافي الثالث: جدار الحماية المُصغّر (Mini Firewall)
سنقوم بمحاكاة جدار حماية بسيط يقوم بفحص قائمة من المنافذ (Ports) ويقرر ما إذا كان يجب حظرها
أم السماح بها بناءً على قاعدة بيانات مصغرة (دالة تقييم)، ثم يعطينا إحصائية نهائية.

المطلوب كتابة برنامج ينفذ الآتي:
1. خارج `main`: قم بكتابة دالة باسم `check_port`.
    - تستقبل الدالة مُعاملًا واحدًا عبارة عن عدد صحيح (رقم المنفذ `int port`).
    - تُرجع الدالة عددًا صحيحًا (`int`).
    - المنطق داخل الدالة: استخدم جملة شرطية `if` للتحقق من المنافذ الخبيثة المعروفة. إذا كان المنفذ يساوي `4444` 
    (منفذ Metasploit الشهير) أو يساوي `135` (منفذ استغلال ثغرات الويندوز) أو يساوي `6667` (منفذ بوتات IRC).. 
    فاجعل الدالة تُرجع الرقم `1` (بمعنى أن المنفذ محظور).
    - عدا ذلك (`else`)، اجعل الدالة تُرجع الرقم `0` (بمعنى أن المنفذ آمن).
        
2. داخل `main`:
    - قم بتعريف مصفوفة أعداد صحيحة مكونة من 5 منافذ لتمثل حركة مرور الشبكة. أعطها القيم التالية: `{80, 4444, 443, 6667, 22}`.
    - قم بتعريف عدادين بصفر: `blocked_count = 0` و `allowed_count = 0`.
    - استخدم حلقة `for` للمرور على جميع عناصر مصفوفة المنافذ.
        
    - داخل الحلقة:
        - قم باستدعاء الدالة `check_port` ومرر لها المنفذ الحالي (`ports[i]`)، واستقبل النتيجة (إما 1 أو 0).
        - استخدم النتيجة في جملة شرطية `if`:
            - إذا كانت النتيجة `1`: اطبع تحذيراً "ALERT: Port [رقم المنفذ] is BLOCKED!"، وقم بزيادة عداد `blocked_count`.
            - إذا كانت النتيجة `0`: اطبع "Port [رقم المنفذ] is Allowed."، وقم بزيادة عداد `allowed_count`.
                
    - بعد انتهاء الحلقة (خارجها):
        - اطبع ملخص الفحص: "Scan Complete. Blocked: [عدد المحظورة], Allowed: [عدد المسموحة]".


#include <stdio.h>
#include <ctype.h>
#include <string.h>

int check_port(int port){
	int	port_status =0;
	if(port == 4444){
		port_status =1;
	}
	else if(port == 135){
		port_status =1;
	}
	else if(port == 6667){
		port_status =1;
	}
	else{
		port_status =0;
	}
	
	return port_status;
}
int main(){
	int ports[5]={80, 4444, 443, 6667, 22};
	int blocked_count = 0;
	int allowed_count = 0;
	for(int port =0; port <5; port++){
		int status = check_port(ports[port]);
		if(status == 1){
			printf("ALERT: Port %d  is BLOCKED!\n",ports[port]);
		}
		if(status == 0){
			printf("ALERT: Port %d    is Allowed!\n",ports[port]);
		}
	}
	
}
*/