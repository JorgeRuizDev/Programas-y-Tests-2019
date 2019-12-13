#!/bin/sh

var="aaa"
echo -e "$var\n"

echo hola

ja="y sus cocretas"
echo arriba españa $ja

echo "set: "

unset ja

echo arriba españa $ja

echo "Variable mal definida, error de orden no encontrada":
VAR = 1
echo "Variables bien definidas:"
VAR=1
VAR1=2
var=3
echo "Variables: $VAR $VAR1 $var"
echo "Variable VAR: $VAR"
echo "Variable VAR1: $VAR1"
echo "Variable VAR seguida de 1 (requiere llaves): ${VAR}1"
echo "Comillas dobles: $VAR"
echo 'Comillas simples: $VAR'
echo "Valor: $VAR-1"
echo "$HOME"


#ejecutar como ./script_var-shell.sh arg1 arg2
echo \$@=$@
echo \$*=$*
echo \$0=$0
echo \$1=$1
echo \$2=$2
echo Cambio parametros posicionales
set uno dos tres
echo \$1=$1
echo \$2=$2
echo Desplazo
shift
echo \$1=$1
echo \$2=$2
echo \$-=$-
echo \$#=$#
echo \$?=$?

ps w
echo \$$=$$
echo \$!=$!


#3.3.4
echo "El comando interno del shell export permite que una variable (previamente definida o no) sea configurada para que su valor sea copiado a los procesos hijos que sean creados desde el shell actual (por ejemplo otros shell). Presenta la sintaxis:"

echo export VAR

echo export VAR=valor

echo "El proceso hijo no puede crear ni modificar variables del proceso padre."

echo "Si se ejecuta con ./ HAY exportación de variables, con . scrpit NO"