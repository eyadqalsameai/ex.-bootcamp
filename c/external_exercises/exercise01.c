#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Exercise One: Username Validator
/*
التمرين الأول: فحص طول اسم المستخدم (Username Validator)
المطلوب منك كتابة برنامج يقوم بالآتي:
    يطلب من المستخدم إدخال اسم المستخدم الخاص به (Username).
    يستقبل الإدخال ويخزنه في متغير مناسب يسمح باستيعاب 15 حرفًا كحد أقصى.
    يطبع رسالة ترحيبية تحتوي على الاسم الذي تم إدخاله.
    يحسب طول هذا الاسم، ويطبعه على الشاشة.
    يستخدم جملة شرطية للتحقق من طول الاسم:
        إذا كان طول الاسم 8 أحرف أو أكثر، يطبع رسالة تفيد بأن طول الاسم مقبول.
        إذا كان أقل من 8 أحرف، يطبع رسالة تفيد بأن الاسم قصير ويحتاج إلى تعديل.
شروط التنفيذ:
    استخدم الدوال والمكتبات المناسبة التي درستها في الملفات المرفقة فقط.
    فكر في كيفية استخدام دالة الإدخال الصحيحة، وكيفية حساب الطول، وما هو نوع البيانات المناسب لتخزين الطول.
*/


/*
int main(){
    char username[16]; // Allowing space for 15 characters + null terminator
    
    printf("Enter your username : ");
    fgets(username,sizeof(username),stdin);
    size_t namelength = strlen(username);
    printf("Welcome: %s \n",username);
    printf("Length of your Name is %zu. \n", namelength -1);
    
    if(namelength - 1 >=8){
    	printf("The name length is acceptable.\n");
    	
    }
    else{
    	printf("The name is short and needs to be modified.\n");
    }
    return 0;
}
*/


// Exercise Two: Password Strength Checker

/*

التمرين الثاني: مقياس قوة كلمة المرور (Password Strength Meter)
المطلوب كتابة برنامج ينفذ الآتي:
    يطلب من المستخدم إدخال كلمة مرور باستخدام دالة fgets.
    يحسب الطول الفعلي للكلمة (استخدم الحل الرياضي لتعويض زيادة fgets).
    يحسب "نسبة الأمان" كقيمة عشرية (float)، بافتراض أن الطول المثالي المعتمد في سياسة التشفير هو 16 حرفًا. 
    (المعادلة: الطول الفعلي مقسومًا على 16، ثم يضرب الناتج في 100).
    يطبع النسبة المئوية على الشاشة مع إظهار رقمين فقط بعد الفاصلة العشرية.
    يقيّم النسبة باستخدام الجمل الشرطية المترابطة (if / else if):
        النسبة 100% أو أكثر: يطبع "أمان عالي".
        النسبة من 50% إلى ما دون 100%: يطبع "أمان متوسط".
        النسبة أقل من 50%: يطبع "أمان ضعيف".
*/


/*
int main(){
    char password[16]; // Allowing space for 15 characters + null terminator
    
    printf("Enter your password : ");
    fgets(password,sizeof(password),stdin);
    size_t passlength = strlen(password);
    printf("Welcome: %s \n",password); 
    printf("Length of your Password is %zu. \n", passlength -1);
    int actual_length = passlength - 1;
    float security_percentage = (float)actual_length / 16 * 100;
    printf("Security percentage: %.2f%%\n", security_percentage);
    
    if(security_percentage >= 100){
        printf("High Security.\n");
    }
    else if(security_percentage >= 50){
        printf("Medium Security.\n");
    }
    else{
        printf("Low Security.\n");
    }
    return 0;
}
*/

// Exercise Three: Token Verifier

/*

التمرين الثالث: نظام التحقق من رمز الدخول (Token Verifier)
في هذا التمرين سنقوم بدمج السلاسل النصية (Strings) مع المتغيرات المنطقية (Booleans) 
للتحقق من هويات المستخدمين استنادًا إلى قواعد محددة.
المطلوب كتابة برنامج ينفذ الآتي:
    يطلب من المستخدم إدخال "رمز الدخول" (Security Token) بحيث لا يتجاوز 20 حرفًا (استخدم fgets).
    يحسب الطول الفعلي للرمز (مع خصم السطر الجديد).
    يقوم بإنشاء متغيرين منطقيين (Booleans) لتقييم الرمز (تذكر استدعاء المكتبة الخاصة بها):
        المتغير الأول is_length_ok: تكون قيمته true إذا كان الطول الفعلي للرمز 8 أحرف أو أكثر.
        المتغير الثاني starts_with_admin: تكون قيمته true إذا كان الحرف الأول من الرمز هو حرف A الكبير.
         (تلميح: تذكر أن السلسلة النصية هي في الأصل مصفوفة، وكيف كنت تصل للعنصر الأول في ملف arrays.c).
    قم بإنشاء متغير منطقي ثالث اسمه is_granted، وتكون قيمته true فقط 
    إذا كان الطول مناسبًا (is_length_ok) وَ كان يبدأ بحرف الإدارة
     (starts_with_admin). (تلميح: استخدم المعامل المنطقي الذي درسته في booleans.c).
    أخيرًا، استخدم جملة if / else بناءً على قيمة المتغير is_granted؛
     فإذا كانت صحيحة اطبع "Access Granted"، وإذا كانت خاطئة اطبع "Access Denied".

*/


/*
int main()
{
    char security_token [20];
    printf("Enter the Security Token: ");
    
    fgets(security_token,sizeof(security_token),stdin);

    size_t lingth_token = strlen(security_token);

    printf("Length of your Token is %zu. \n", lingth_token -1);
    int actual_length = lingth_token - 1;

    bool is_length_ok = false;
    bool starts_with_admin = false;
    bool is_granted = false;

    if(actual_length >=8 ){
        is_length_ok =true;
    }
    if(security_token[0] == 'A'){
        starts_with_admin = true;
    }
    if(is_length_ok && starts_with_admin == true){
        is_granted=true;
    }
    if (is_granted ==true){
        printf("Access Granted.\n");
    }
    else{
        printf("Access Denied.\n");
    }

    return 0;
}
*/

// 

/* Exercise Four: Security Log Analyzer

التمرين الرابع: محلل السجلات الأمنية (Security Log Analyzer)
المطلوب كتابة برنامج ينفذ الآتي:
    قم بتعريف متغير من نوع عدد صحيح (int) باسم event_id وأعطه القيمة الافتراضية 4625 (وهو رمز فشل تسجيل الدخول في أنظمة ويندوز).
    اطلب من المستخدم إدخال اسم الحساب (Account Name) الذي تسبب في الحدث، واستقبله باستخدام fgets.
    احسب الطول الفعلي لاسم الحساب.
    استخدم جملة switch لفحص المتغير event_id:
        إذا كان 4624: اطبع "Event: Successful Logon".
        إذا كان 4625: اطبع "Event: Failed Logon".
        الحالة الافتراضية (default): اطبع "Event: Unknown".
    قم بحساب "مؤشر الشك" (Suspicion Score) كقيمة عشرية (float). المعادلة: (الطول الفعلي لاسم الحساب مقسوماً على 15)
     مضروباً في 100. واطبعه مع رقمين عشريين.
    قم بإنشاء متغير منطقي باسم is_high_risk تكون قيمته true إذا تحقق أحد الشرطين التاليين
     (استخدم المعامل المنطقي || الذي يعني "أو"):
        مؤشر الشك أعلى من أو يساوي 75.00.
        الحرف الأول من اسم الحساب هو الحرف R (إشارة لمحاولة الدخول بحساب Root).
    أخيراً، استخدم if / else لتقييم is_high_risk. إذا كان صحيحاً، اطبع تنبيهاً أمنياً 
    "ALERT: High Risk Activity Detected!"، وإلا اطبع "Log Analyzed: Normal Activity".
*/
int main()
{
    int event_id = 4625;
    char account_name[15];
    printf("Enter Account Name: ");
    fgets(account_name,sizeof(account_name),stdin);

    switch (event_id)
    {
    case 4624:
        printf("Event: Seccessful Logon\n");
        break;
    case 4625:
        printf("Event: Failed Logon\n");
        break;
    
    default:
        printf("Event: Unknown\n");
        break;
    }
    size_t length_account_name=strlen(account_name);
    int actual_length =length_account_name -1;

    float suspicion_score = (float) actual_length / 15 * 100;

    printf("Suspicion Score: %.2f \n", suspicion_score);
    
    bool is_high_risk = false;

    if(suspicion_score >= 75.00 || account_name[0]== 'R'){
        is_high_risk=true;
    }

    if (is_high_risk == true)
    {
        printf("ALERT: High Risk Activity Detected!\n");
    }
    else{
        printf("Log Analyzed: Normal Activity\n");
    }
    
    return 0;
}