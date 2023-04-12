#!/bin/bash

COUNTER_SUCCES=0
COUNTER_FAIL=0
DIFF=""
FILE1="../../test/test.txt"
FILE2="../../test/test2.txt"
FILE3="../../test/test3.txt"
TEMP_FILE="../../test/temp.txt"
TEMP="asd"


echo "запускаем тестирование"

#Тест с флагом Е
TEST_E="-e $TEMP $FILE1 $FILE2 $FILE3"
./s21_grep $TEST_E > s21_grep.txt
grep $TEST_E > grep.txt
DIFF="$(diff -b s21_grep.txt grep.txt)"
if [ "$DIFF" == "" ]
    then
        ((COUNTER_SUCCES++))
        echo "Тест с флагом Е прошел успешно"
    else
        ((COUNTER_FAIL++))
        echo "Тест с флагом Е успешно ЗАВАЛЕН"
        diff -b -C 2 grep.txt s21_grep.txt >> ../../test/log_grep.txt
    fi

rm s21_grep.txt grep.txt

#Тест с флагом I
TEST_E="-i $TEMP $FILE1 $FILE2 $FILE3"
./s21_grep $TEST_E > s21_grep.txt
grep $TEST_E > grep.txt
DIFF="$(diff -b s21_grep.txt grep.txt)"
if [ "$DIFF" == "" ]
    then
        ((COUNTER_SUCCES++))
        echo "Тест с флагом I прошел успешно"
    else
        ((COUNTER_FAIL++))
        echo "Тест с флагом I успешно ЗАВАЛЕН"
        diff -b -C 2 grep.txt s21_grep.txt >> ../../test/log_grep.txt
    fi
rm s21_grep.txt grep.txt

#Тест с флагом V
TEST_E="-v $TEMP $FILE1 $FILE2 $FILE3"
./s21_grep $TEST_E > s21_grep.txt
grep $TEST_E > grep.txt
DIFF="$(diff -b s21_grep.txt grep.txt)"
if [ "$DIFF" == "" ]
    then
        ((COUNTER_SUCCES++))
        echo "Тест с флагом V прошел успешно"
    else
        ((COUNTER_FAIL++))
        echo "Тест с флагом V успешно ЗАВАЛЕН"
        diff -b -C 2 grep.txt s21_grep.txt >> ../../test/log_grep.txt
    fi
rm s21_grep.txt grep.txt

#Тест с флагом C
TEST_E="-c $TEMP $FILE1 $FILE2 $FILE3"
./s21_grep $TEST_E > s21_grep.txt
grep $TEST_E > grep.txt
DIFF="$(diff -b s21_grep.txt grep.txt)"
if [ "$DIFF" == "" ]
    then
        ((COUNTER_SUCCES++))
        echo "Тест с флагом C прошел успешно"
    else
        ((COUNTER_FAIL++))
        echo "Тест с флагом C успешно ЗАВАЛЕН"
        diff -b -C 2 grep.txt s21_grep.txt >> ../../test/log_grep.txt
    fi
rm s21_grep.txt grep.txt

#Тест с флагом L
TEST_E="-l $TEMP $FILE1 $FILE2 $FILE3"
./s21_grep $TEST_E > s21_grep.txt
grep $TEST_E > grep.txt
DIFF="$(diff -b s21_grep.txt grep.txt)"
if [ "$DIFF" == "" ]
    then
        ((COUNTER_SUCCES++))
        echo "Тест с флагом L прошел успешно"
    else
        ((COUNTER_FAIL++))
        echo "Тест с флагом L успешно ЗАВАЛЕН"
        diff -b -C 2 grep.txt s21_grep.txt >> ../../test/log_grep.txt
    fi
rm s21_grep.txt grep.txt

#Тест с флагом N
TEST_E="-n $TEMP $FILE1 $FILE2 $FILE3"
./s21_grep $TEST_E > s21_grep.txt
grep $TEST_E > grep.txt
DIFF="$(diff -b s21_grep.txt grep.txt)"
if [ "$DIFF" == "" ]
    then
        ((COUNTER_SUCCES++))
        echo "Тест с флагом N прошел успешно"
    else
        ((COUNTER_FAIL++))
        echo "Тест с флагом N успешно ЗАВАЛЕН"
        diff -b -C 2 grep.txt s21_grep.txt >> ../../test/log_grep.txt
    fi
rm s21_grep.txt grep.txt

#Тест с флагом H
TEST_E="-h $TEMP $FILE1 $FILE2 $FILE3"
./s21_grep $TEST_E > s21_grep.txt
grep $TEST_E > grep.txt
DIFF="$(diff -b s21_grep.txt grep.txt)"
if [ "$DIFF" == "" ]
    then
        ((COUNTER_SUCCES++))
        echo "Тест с флагом H прошел успешно"
    else
        ((COUNTER_FAIL++))
        echo "Тест с флагом H успешно ЗАВАЛЕН"
        diff -b -C 2 grep.txt s21_grep.txt >> ../../test/log_grep.txt
    fi
rm s21_grep.txt grep.txt

#Тест с флагом S
TEST_E="-s $TEMP $FILE1 $FILE2 $FILE3 test4.txt"
./s21_grep $TEST_E > s21_grep.txt
grep $TEST_E > grep.txt
DIFF="$(diff -b s21_grep.txt grep.txt)"
if [ "$DIFF" == "" ]
    then
        ((COUNTER_SUCCES++))
        echo "Тест с флагом S прошел успешно"
    else
        ((COUNTER_FAIL++))
        echo "Тест с флагом S успешно ЗАВАЛЕН"
        diff -b -C 2 grep.txt s21_grep.txt >> ../../test/log_grep.txt
    fi
rm s21_grep.txt grep.txt

#Тест с флагом F
TEST_E="-f $TEMP_FILE $FILE1 $FILE2 $FILE3"
./s21_grep $TEST_E > s21_grepF.txt
grep $TEST_E > grepF.txt
DIFF="$(diff -b s21_grepF.txt grepF.txt)"
if [ "$DIFF" == "" ]
    then
        ((COUNTER_SUCCES++))
        echo "Тест с флагом F прошел успешно"
    else
        ((COUNTER_FAIL++))
        echo "Тест с флагом F успешно ЗАВАЛЕН"
        diff -b -C 2 grepF.txt s21_grepF.txt >> ../../test/log_grep.txt
    fi
rm s21_grepF.txt grepF.txt

#Тест с флагом O
TEST_E="-o $TEMP $FILE1 $FILE2 $FILE3"
./s21_grep $TEST_E > s21_grep.txt
grep $TEST_E > grep.txt
DIFF="$(diff -b s21_grep.txt grep.txt)"
if [ "$DIFF" == "" ]
    then
        ((COUNTER_SUCCES++))
        echo "Тест с флагом O прошел успешно"
    else
        ((COUNTER_FAIL++))
        echo "Тест с флагом O успешно ЗАВАЛЕН"
        diff -b -C 2 grep.txt s21_grep.txt >> ../../test/log_grep.txt
    fi
rm s21_grep.txt grep.txt

echo "Успешных тестов - $COUNTER_SUCCES"
echo "Проваленных тестов - $COUNTER_FAIL"