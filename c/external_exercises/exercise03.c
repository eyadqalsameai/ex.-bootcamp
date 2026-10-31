// Exercise One: Threat Level Analyzer
/*
التمرين الأول (مراجعة قصيرة)
سنبدأ بتمرين يراجع أهم مهارات اليومين السابقين مع التركيز على الأخطاء
التي وقعت فيها (تحديداً: حفظ القيمة العائدة من الدالة، والتفريق بين المصفوفة وعناصرها).
اسم التمرين: محلل مستوى التهديد (Threat Level Analyzer)
المطلوب:
    خارج main: أنشئ دالة تُرجع رقماً صحيحاً (int)، وسمِّها find_max_threat.
        تستقبل الدالة معاملين: الأول مصفوفة أرقام صحيحة (تمثل مستويات التهديد)، والثاني رقم صحيح يمثل "حجم المصفوفة".
        داخل الدالة: استخدم حلقة تكرار للبحث عن "أعلى رقم" في المصفوفة، ثم أرجع هذا الرقم باستخدام return.
        (تلميح: عرّف متغيراً في البداية وافترض أن قيمته هي العنصر الأول في المصفوفة，
         ثم قارنه ببقية العناصر لتحديثه إذا وجدت ما هو أكبر منه).
    داخل main:
        عرّف مصفوفة أرقام صحيحة مكونة من 5 عناصر، وأعطها مستويات تهديد عشوائية (مثلاً: 45, 12, 89, 33, 70).
        استدعِ الدالة find_max_threat. (تذكر خطأك السابق: يجب أن تستقبل النتيجة وتحفظها في متغير جديد!).
        اطبع النتيجة للمستخدم كالتالي: "CRITICAL: Maximum threat level detected is: [الرقم]"



#include <stdio.h>
#include <ctype.h>
#include <string.h>

int find_max_threat(int level_threat[], int size_threat){
	int max_threat =level_threat[0];
	for(int max_level =0; max_level	< size_threat ; max_level++){
		if(level_threat[max_level] > max_threat){
			max_threat = level_threat[max_level];
		}
	}
	
	return max_threat;
}

int main(){
	int	level_threat[5]={45, 12, 89, 33, 70};
	int threat = find_max_threat(level_threat, 5);
	printf("\nCRITICAL: Maximum threat level detected is: [%d]\n",threat);
	return 0;
}
*/

// Exercise Two: Dynamic Buffer Allocator

/*
التمرين الثاني: مُخصص الحافظة الديناميكي (Dynamic Buffer Allocator)

في الأنظمة الأمنية، لا نعرف دائماً حجم البيانات التي سنستقبلها (مثل عدد الـ IPs المهاجمة)، لذلك
نحتاج لحجز الذاكرة أثناء تشغيل البرنامج بناءً على الحاجة، ثم تحريرها فور الانتهاء لمنع تسرب الذاكرة (Memory Leak).
المطلوب كتابة برنامج ينفذ الآتي داخل دالة `main`:_(تأكد من تضمين مكتبة `<stdlib.h>` 
للتعامل مع الذاكرة)._
1. معرفة الحجم المطلوب: اطلب من المستخدم إدخال عدد الـ IPs المشبوهة التي يريد فحصها. 
استقبل الرقم باستخدام `scanf` واحفظه في متغير (مثلاً `n`).
2. حجز الذاكرة: استخدم الدالة `malloc` لحجز مساحة في الذاكرة تكفي لعدد `n` من الأعداد
الصحيحة `int`، واحفظ العنوان في مؤشر (مثلاً `int *buffer`).
3. فحص الأمان: استخدم جملة `if` للتحقق مما إذا كان المؤشر `buffer` يساوي `NULL` (أي أن حجز
الذاكرة فشل). إذا فشل، اطبع رسالة خطأ وأنهِ البرنامج باستخدام `return 1;`.
4. تعبئة البيانات بطريقة المؤشرات (التحدي هنا):
    - استخدم حلقة `for` تبدأ من 0 وتنتهي قبل `n`.
    - شرط إلزامي: يُمنع استخدام الأقواس المربعة `[]` للوصول للذاكرة.
	بدلاً من ذلك، استخدم حسابات المؤشرات لتعيين القيم. اجعل كل عنصر يساوي قيمة العداد مضروباً في 100. 
    _(تلميح: استخدم الشكل `*(buffer + i) = ...` كما درسته في الملفات)_.
5. الطباعة: استخدم حلقة `for` أخرى لطباعة جميع القيم المخزنة، واستخدم أيضاً طريقة المؤشرات `*(buffer + i)` في جملة الطباعة.
6. تنظيف الذاكرة: في نهاية البرنامج، استخدم الدالة `free` لتحرير المؤشر `buffer` لمنع أي تسرب للذاكرة (Memory Leak).

*/

#include <stdlib.h>
#include <stdio.h>
int main(){
	int ips;
	printf("Enter IPs you need to scan: ");
	scanf("%d", &ips);
	
	int actaul_ips = ips;
	int *buffer = (int*) malloc(actaul_ips * sizeof(int));
	if(buffer == NULL){
		printf("Memory Allocation Failed!\n");
		return 1;
	}
	for(int i =0; i < actaul_ips; i++){
		*(buffer + i) = i * 100;
	}
	for(int i =0; i < actaul_ips; i++){
		printf("Buffer[%d] = %d\n", i, *(buffer + i));
	}
	free(buffer);
	return 0;
}