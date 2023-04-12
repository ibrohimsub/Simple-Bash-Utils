#!/bin/bash

COUNTER_SUCCES=0
COUNTER_FAIL=0
DIFF=""
FILE1="../../test/test.txt"
FILE2="../../test/test2.txt"
FILE3="../../test/test3.txt"

echo "запускаем тестирование"

#Тест с флагом -b
TEST_E="-b $FILE1 $FILE2 $FILE3"
./s21_cat $TEST_E > s21.txt
cat $TEST_E > cat.txt
DIFF="$(diff -b s21.txt cat.txt)"
if [ "$DIFF" == "" ]
    then
        ((COUNTER_SUCCES++))
        echo "Тест с флагом -b прошел успешно"
    else
        ((COUNTER_FAIL++))
        echo "Тест с флагом -b успешно ЗАВАЛЕН"
        diff -b -C 2 cat.txt s21.txt >> ../../test/log_cat.txt
    fi

rm s21.txt cat.txt

#Тест с флагом -n
TEST_E="-n $FILE1 $FILE2 $FILE3"
./s21_cat $TEST_E > s21.txt
cat $TEST_E > cat.txt
DIFF="$(diff -b s21.txt cat.txt)"
if [ "$DIFF" == "" ]
    then
        ((COUNTER_SUCCES++))
        echo "Тест с флагом -n прошел успешно"
    else
        ((COUNTER_FAIL++))
        echo "Тест с флагом -n успешно ЗАВАЛЕН"
        diff -b -C 2 cat.txt s21.txt >> ../../test/log_cat.txt
    fi

rm s21.txt cat.txt

#Тест с флагом -s
TEST_E="-s $FILE1 $FILE2 $FILE3"
./s21_cat $TEST_E > s21.txt
cat $TEST_E > cat.txt
DIFF="$(diff -b s21.txt cat.txt)"
if [ "$DIFF" == "" ]
    then
        ((COUNTER_SUCCES++))
        echo "Тест с флагом -s прошел успешно"
    else
        ((COUNTER_FAIL++))
        echo "Тест с флагом -s успешно ЗАВАЛЕН"
        diff -b -C 2 cat.txt s21.txt >> ../../test/log_cat.txt
    fi

rm s21.txt cat.txt

#Тест с флагом -t
TEST_E="-t $FILE1 $FILE2 $FILE3"
./s21_cat $TEST_E > s21.txt
cat $TEST_E > cat.txt
DIFF="$(diff -b s21.txt cat.txt)"
if [ "$DIFF" == "" ]
    then
        ((COUNTER_SUCCES++))
        echo "Тест с флагом -t прошел успешно"
    else
        ((COUNTER_FAIL++))
        echo "Тест с флагом -t успешно ЗАВАЛЕН"
        diff -b -C 2 cat.txt s21.txt >> ../../test/log_cat.txt
    fi

rm s21.txt cat.txt

#Тест с флагом -e
TEST_E="-e $FILE1 $FILE2 $FILE3"
./s21_cat $TEST_E > s21.txt
cat $TEST_E > cat.txt
DIFF="$(diff -b s21.txt cat.txt)"
if [ "$DIFF" == "" ]
    then
        ((COUNTER_SUCCES++))
        echo "Тест с флагом -e прошел успешно"
    else
        ((COUNTER_FAIL++))
        echo "Тест с флагом -e успешно ЗАВАЛЕН"
        diff -b -C 2 cat.txt s21.txt >> ../../test/log_cat.txt
    fi

rm s21.txt cat.txt


echo "Успешных тестов - $COUNTER_SUCCES"
echo "Проваленных тестов - $COUNTER_FAIL"