####基础类####
#数字字符和数字字符串
[define]
dig=[0~9]
number=[$dig][$number,]

#空格类的字符和字符串
blank=[\x01~\x20]
space=[$blank][$space,]

#可用英文字母
ch=[A~Z,a~z,_]
equ=[=]
#16进制字符串
hch=[A~F,a~f,$dig]
hexc=[$hch][$hexc,]
#可用英文字母和数字
char=[$ch,$dig]

#命名字符串规则
postfix=([$char][$postfix,],)

#命名规范-必须以英文字母开头
wd=[$ch][$postfix]

####元素类####
#关键字


strcont=(\\?,<\">?)
charscont=(\\?,<\'>?)

[meta]
#关键字识别
k_space=($space)
k_import=import<$char>
k_cdecl=cdecl<$char>
k_stdcall=stdcall<$char>
k_fastcall=fastcall<$char>
k_pascal=pascal<$char>
k_operator=operator<$char>
k_for=for<$char>
k_while=while<$char>
k_do=do<$char>
k_try=try<$char>
k_catch=catch<$char>
k_if=if<$char>
k_break=break<$char>
k_continue=continue<$char>
k_default=default<$char>
k_interface=interface<$char>
k_class=class<$char>
k_package=package<$char>
k_static=static<$char>
k_const=const<$char>
k_throw=throw<$char>
k_switch=switch<$char>
k_case=case<$char>
k_else=else<$char>
k_return=return<$char>
k_new=new<$char>
k_include=include<$char>
k_using=using<$char>
k_require=require<$char>
k_finally=finally<$char>
k_final=final<$char>
k_synchronized_read=synchronized_read<$char>
k_synchronized_write=synchronized_write<$char>
k_synchronized=synchronized<$char>
k_declare=@Declare<$char>
#十六进制数
hex=0x($hexc)

#浮点数 三种形式 0.6f .6f 0.6 识别优先级高于long
float=($number[.]($number,)[f,F],[.]($number)[f,F],$number[.]$number)

#长整数 识别优先级高于int
longnum=($number)[l,L]

#整数
intnum=($number)

word=($wd)

####符号类####
colon=[\:]
qm=[\?]
#注释
comment=[/\**\*/,//*\n]

#复合赋值运算 结合性:从右到左
compset_ops=[\>\>=,\<\<=,|=,^=,&=,%=,/=,\*=,-=,+=]

#逻辑或运算
logicor_ops=[||]

#逻辑与运算
logicand_ops=[&&]

#位或运算
bitor_ops=[|]

#位异或运算
bitxor_ops=[^]

#位并运算
bitand_ops=[&]

#等于运算
equals_ops=[==,!=]

#位移运算
bitmov_ops=[\<\<]

#比较运算
meq=[\>=]
leq=[\<=]
lc=[\<]
rc=[\>]


#自操作运算
self_ops=[++,--]

#一元运算
unary_ops=[!,\~]

#加减运算
addsub_ops=[+,-]

#乘除取余运算
muldivmod_ops=[\*,/,%]

mov=[=]

dot=[.]

lb=[\(]
rb=[\)]
ll=[\{]
lr=[\}]
ls=[\[]
rs=[\]]
le=[;]
comma=[\,]
string="({$strcont},)"
chars='({$charscont},)'


[ignore]
comment=true
k_space=true

[syntax]
#############################数学运算#############################
#复合赋值运算  自右向左
compset_symbol=[$compset_ops,$mov]
compset_operation=($normal_object)($compset_symbol)($object)

#三元运算 自右向左
binary_expression=($object)($qm)($object)($colon)($object)

#逻辑或运算
logicor_symbol=[$logicor_ops]
logicor_operator=($logicand_operation,$logicand_operator)
logicor_operation=([$logicor_operation],$logicor_operator)($logicor_symbol)($logicor_operator)

#逻辑与运算
logicand_symbol=[$logicand_ops]
logicand_operator=($bitor_operation,$bitor_operator)
logicand_operation=([$logicand_operation],$logicand_operator)($logicand_symbol)($logicand_operator)

#位或运算
bitor_symbol=[$bitor_ops]
bitor_operator=($bitxor_operation,$bitxor_operator)
bitor_operation=([$bitor_operation],$bitor_operator)($bitor_symbol)($bitor_operator)

#位异或运算
bitxor_symbol=[$bitxor_ops]
bitxor_operator=($bitand_operation,$bitand_operator)
bitxor_operation=([$bitxor_operation],$bitxor_operator)($bitxor_symbol)($bitxor_operator)

#位与运算
bitand_symbol=[$bitand_ops]
bitand_operator=($equals_operation,$equals_operator)
bitand_operation=([$bitand_operation],$bitand_operator)($bitand_symbol)($bitand_operator)

#等于运算
equals_symbol=[$equals_ops]
equals_operator=($compare_operation,$compare_operator)
equals_operation=([$equals_operation],$equals_operator)($equals_symbol)($equals_operator)

#比较运算
compare_symbol=[$meq,$rc,$leq,$lc]
compare_operator=($bitmov_operation,$bitmov_operator)
compare_operation=([$compare_operation],$compare_operator)($compare_symbol)($compare_operator)

#位移运算 由于和模板的>>冲突  于是这里改成两个rc
bitmov_symbol=[$bitmov_ops,[$rc][$rc]]
bitmov_operator=($addsub_operation,$addsub_operator)
bitmov_operation=([$bitmov_operation],$bitmov_operator)($bitmov_symbol)($bitmov_operator)

#加减法运算
addsub_symbol=[$addsub_ops]
addsub_operator=($muldivmod_operation,$muldivmod_operator)
addsub_operation=([$addsub_operation],$addsub_operator)($addsub_symbol)($addsub_operator)

#乘除取余运算
muldivmod_symbol=[$muldivmod_ops]
muldivmod_operator=($unary_operation,$unary_operator)
muldivmod_operation=([$muldivmod_operation],$muldivmod_operator)($muldivmod_symbol)($muldivmod_operator)

#一元运算  自右向左
unary_symbol=[$unary_ops,$self_ops,$addsub_ops]
unary_operator=($normal_object)
unary_operation=(($unary_symbol)([$unary_operation],$unary_operator),([$unary_operation],$unary_operator)($self_ops))

#############################语法定义#############################
#算子

#顶级元素 常量
const_object=[$hex,$longnum,$intnum,$float,$string,$chars]
word_exp=($word)
meta_object=[($k_operator)($compset_symbol,$logicor_ops,$logicand_ops,$bitor_ops,$bitxor_ops,$bitand_ops,$equals_ops,$bitmov_ops,$compare_symbol,$self_ops,$unary_ops,$addsub_ops,$muldivmod_ops,$dot,($ls)($rs)),($word_exp)]

#顶级元素 对象
#静态的取属性表达式  只能用于new 对象的时候使用
static_ownner=([$static_ownner],$template_object,$object_block,$word_exp,$const_object)[$dot]($meta_object)
static_element=([$static_element],($static_ownner),$object_block,($word_exp))[$ls]($object)[$rs]
template_object=($static_ownner,$object_block,$word_exp)[$lc]($template_params)[$rc]

new_expression=[$k_new]($template_object,$static_ownner,$object_block,$word_exp)($lb)($array,)($rb)
array_type=($array_type,$template_object,$static_ownner,$object_block,$word_exp)[$ls][$rs]
new_array=([$new_array],$template_object,$static_ownner,$object_block,$word_exp)[$ls]($object)[$rs]
newarray_expression=[$k_new]($new_array)


dynamic_ownner=([$dynamic_ownner],$new_expression,$newarray_expression,$dynamic_element,$static_element,$call_expression,$temporary_class)[$dot]($meta_object)
dynamic_element=([$dynamic_element],$call_expression,$dynamic_ownner)[$ls]($object)[$rs]

call_expression=($dynamic_ownner,$static_ownner,$meta_object)($lb)($array,)($rb)

static_type=($template_object,$array_type,$static_ownner,$word_exp)

#表达式定义
object_block=($lb)([$object_block],$object)($rb)
cast_object=($object_block)($normal_object)
return_expression=($k_return)($object,)
throw_expression=($k_throw)($object,)

#
normal_expression=(($synchronized_expression,$if_expression,$for_expression,$while_expression,$dowhile_expression,$switch_expression,$exception_expression,$def_variable_state,$function),($class,$object,$k_break,$k_continue,$throw_expression,$return_expression)($le))
#############################对象定义#############################
#语法对象 
##############################集合
#这些是没有任何优先级的
normal_object=($cast_object,$init_list,$call_expression,$dynamic_element,$dynamic_ownner,$temporary_class,$newarray_expression,$new_expression,$template_object,$static_element,$static_ownner,$object_block,$word_exp,$const_object)

#数学运算表达式 这些是带有优先级的
math_object:=($compset_operation,$binary_expression,$logicor_operation,$logicand_operation,$bitor_operation,$bitxor_operation,$bitand_operation,$equals_operation,$compare_operation,$bitmov_operation,$addsub_operation,$muldivmod_operation,$unary_operation)

#带括号的对象

object=($math_object,$normal_object)

#############################函数运算#############################
#调用函数 #参与数学和逻辑运算
#
temporary_class=($new_expression)($ll)($class_body,)($lr)
array=:([$array][$comma],)($object)
template_params=([$template_params][$comma],)($static_type)
init_list=($ll)($array)($lr)

#############################特殊表达式#############################
#special
synchronized_expression=($k_synchronized,$k_synchronized_read,$k_synchronized_write)(($lb)($static_ownner,$word_exp)($rb))($ll)($statements,)($lr)
if_expression=:($k_if)($lb)($object)($rb)($statement)(($k_else)($statement),)
for_first_expression=[[$for_first_expression][$comma],]($variable_def,$object)
for_last_expression=[[$for_last_expression][$comma],]($object)
for_in_expression=$object
#for表达式
for_expression=($k_for)($lb)($for_first_expression,)($le)($for_in_expression,)($le)($for_last_expression,)($rb)($statement)

#while表达式
while_expression=($k_while)($lb)($object)($rb)($statement)

#dowhile表达式
dowhile_expression=($k_do)($statement)($k_while)($lb)($object)($rb)($le)

#case表达式
case_expression=[$case_expression,](($k_case)($object),$k_default)($colon)($statements,)
#switch表达式
switch_expression=($k_switch)($lb)($object)($rb)($ll)($case_expression)($lr)

#try catch表达式
catch_body=[$catch_body,]($k_catch)($lb)($object)($word_exp)($rb)($ll)($statements,)($lr)
exception_expression=($k_try)($ll)($statements,)($lr)($catch_body,)(($k_finally)($ll)($statements,)($lr),)

#############################语法结构#############################
statement=([$ll]($statements,)[$lr],$normal_expression)
statements=[$statements,]($statement)
variable_init=:[$variable_init($comma),]($word_exp)[($mov)($object),]

#变量定义
variable_def=($k_static,)($k_const,)($static_type)($variable_init)
def_variable_state=($variable_def)($le)

#参数定义
params_def=([$params_def][$comma],)($static_type)($word_exp,)

#调用本地函数的参数类型
nativeparams_def=([$nativeparams_def][$comma],)(($word_exp)($word_exp,))
#include语法
filearray=([$filearray][$comma],)($string)
require=($k_require)($lb)($filearray)($rb)
include=($k_include)($lb)($filearray)($rb)

package_name=[[$package_name][$dot]($word_exp),($word_exp)]
package_array=[[$package_array],]($package_name)[$le]
using=[$k_using][$ll]($package_array)[$lr][$le]
#函数定义
function=(($k_final)($k_static),($k_static)($k_final),$k_final,$k_static,)($static_type)($word_exp)($lb)($params_def,)($rb)($ll)($statements,)($lr)
function_ctor=($word_exp)($lb)($params_def,)($rb)($ll)($statements,)($lr)
function_ctor_declare=($word_exp)($lb)($params_def,)($rb)($le)
operator=(($k_final)($k_static),($k_static)($k_final),$k_final,$k_static,)($static_type)($k_operator)($compset_symbol,$logicor_ops,$logicand_ops,$bitor_ops,$bitxor_ops,$bitand_ops,$equals_ops,$bitmov_ops,$compare_symbol,$self_ops,$unary_ops,$addsub_ops,$muldivmod_ops,$dot,($ls)($rs))($lb)($params_def,)($rb)($ll)($statements,)($lr)
dispatch=($function_ctor,$function_ctor_declare,$function,$operator)
baseclass=[$colon]([$lc]($template_params)[$rc],$static_type)
nativefunction_def=($static_type)($k_cdecl,$k_stdcall,$k_fastcall,$k_pascal)($word_exp)($lb)($nativeparams_def,)($rb)($le)
native_import_body=:[$native_import_body,]($nativefunction_def,)
native_import=($k_import)($string)($ll)($native_import_body,)($lr)($le)
#类定义
class_body=:[$class_body,]($dispatch,$interface_dispatch,$native_import,$class,$interface,$def_variable_state)
#包括模板类
class=(($k_final)($k_static),($k_static)($k_final),$k_final,$k_static,)($k_class)($word_exp)([$lc]($template_params)[$rc],)($baseclass,)($ll)($class_body,)($lr)($le)

baseinterface=[$colon]($static_type)
function_declare=(($k_final)($k_static),($k_static)($k_final),$k_final,$k_static,)($static_type)($word_exp)($lb)($params_def,)($rb)($le)
operator_declare=(($k_final)($k_static),($k_static)($k_final),$k_final,$k_static,)($static_type)($k_operator)($compset_symbol,$logicor_ops,$logicand_ops,$bitor_ops,$bitxor_ops,$bitand_ops,$equals_ops,$bitmov_ops,$compare_symbol,$self_ops,$unary_ops,$addsub_ops,$muldivmod_ops,$dot,($ls)($rs))($lb)($params_def,)($rb)($le)
interface_dispatch=($function_declare,$operator_declare,$interface)
interface_body=:[$interface_body,]($interface_dispatch)
interface=($k_interface)($word_exp)($baseinterface,)($ll)($interface_body,)($lr)($le)

package_body=[$package_body,]($package,$class,$interface)
package=[$k_package]($word_exp)[$ll]($package_body,)[$lr][$le]
declare=($k_declare)($package,$class,$interface)
#############################语言架构#############################
global=:[$global,]($declare,$function,$using,$include,$require,$native_import,$package,$def_variable_state,$class,$interface,($object)($le))

[scan]
scan:=($global)