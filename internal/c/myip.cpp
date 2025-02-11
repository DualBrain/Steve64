//Note: Updated 23/9/2018: Switched to www.qb64.org since .net is down; replaces implementation with download sample code from wiki
//Note: Updated 26/3/2014: Switched to WWW.QB64.NET to avoid IP changes when QB64 moves servers
//Note: Updated 16/1/2013: Switched to QB64.NET IP service
//Note: Updated 15/7/2013: Switched to 223.27.25.123 because of DNS issues

/*
    'ip.php:
    '<?php
    '$ip = $_SERVER["REMOTE_ADDR"];
    'echo $ip;
    '?>
    PRINT whatismyip$

    $CHECKING:OFF
    FUNCTION whatismyip$
        url$ = "www.qb64.org/ip.php"
        url2$ = url$
        x = INSTR(url2$, "/")
        IF x THEN url2$ = LEFT$(url$, x - 1)
        client = _OPENCLIENT("TCP/IP:80:" + url2$)
        IF client = 0 THEN EXIT FUNCTION
        e$ = CHR$(13) + CHR$(10) ' end of line characters
        url3$ = RIGHT$(url$, LEN(url$) - x + 1)
        x$ = "GET " + url3$ + " HTTP/1.1" + e$
        x$ = x$ + "Host: " + url2$ + e$ + e$
        PUT #client, , x$
        t! = TIMER ' start time
        DO
            _DELAY 0.05 ' 50ms delay (20 checks per second)
            GET #client, , a2$
            a$ = a$ + a2$
            i = INSTR(a$, "Content-Length:")
            IF i THEN
                i2 = INSTR(i, a$, e$)
                IF i2 THEN
                    l = VAL(MID$(a$, i + 15, i2 - i - 14))
                    i3 = INSTR(i2, a$, e$ + e$)
                    IF i3 THEN
                        i3 = i3 + 4 'move i3 to start of data
                        IF (LEN(a$) - i3 + 1) = l THEN
                            CLOSE client ' CLOSE CLIENT
                            d$ = MID$(a$, i3, l)

                            'check IP format:
                            i = 0 'total dots
                            x$ = "" 'current number
                            FOR i2 = 1 TO LEN(d$)
                                IF ASC(d$, i2) = 46 THEN
                                    IF LEN(x$) = 0 THEN EXIT FUNCTION
                                    x$ = ""
                                    i = i + 1
                                    IF i > 3 THEN EXIT FUNCTION
                                ELSEIF ASC(d$, i2) < 48 OR ASC(d$, i2) > 57 THEN
                                    EXIT FUNCTION
                                ELSE
                                    x$ = x$ + MID$(d$, i2, 1)
                                END IF
                            NEXT

                            whatismyip$ = d$
                            EXIT FUNCTION
                        END IF ' availabledata = l
                    END IF ' i3
                END IF ' i2
            END IF ' i
        LOOP UNTIL TIMER > t! + 5 ' (in seconds)
        CLOSE client
    END FUNCTION
    $CHECKING:ON
*/

qbs* WHATISMYIP(){ //changed name from FUNC_WHATISMYIP to WHATISMYIP
    qbs *tqbs;
    ptrszint tmp_long;
    int32 tmp_fileno;
    uint32 qbs_tmp_base=qbs_tmp_list_nexti;
    uint8 *tmp_mem_static_pointer=mem_static_pointer;
    uint32 tmp_cmem_sp=cmem_sp;
    
    
    //data1.txt
    qbs *_FUNC_WHATISMYIP_STRING_WHATISMYIP=NULL;
    if (!_FUNC_WHATISMYIP_STRING_WHATISMYIP)_FUNC_WHATISMYIP_STRING_WHATISMYIP=qbs_new(0,0);
    qbs *_FUNC_WHATISMYIP_STRING_URL=NULL;
    if (!_FUNC_WHATISMYIP_STRING_URL)_FUNC_WHATISMYIP_STRING_URL=qbs_new(0,0);
    qbs *_FUNC_WHATISMYIP_STRING_URL2=NULL;
    if (!_FUNC_WHATISMYIP_STRING_URL2)_FUNC_WHATISMYIP_STRING_URL2=qbs_new(0,0);
    float *_FUNC_WHATISMYIP_SINGLE_X=NULL;
    if(_FUNC_WHATISMYIP_SINGLE_X==NULL){
    _FUNC_WHATISMYIP_SINGLE_X=(float*)mem_static_malloc(4);
    *_FUNC_WHATISMYIP_SINGLE_X=0;
    }
    float *_FUNC_WHATISMYIP_SINGLE_CLIENT=NULL;
    if(_FUNC_WHATISMYIP_SINGLE_CLIENT==NULL){
    _FUNC_WHATISMYIP_SINGLE_CLIENT=(float*)mem_static_malloc(4);
    *_FUNC_WHATISMYIP_SINGLE_CLIENT=0;
    }
    qbs *_FUNC_WHATISMYIP_STRING_E=NULL;
    if (!_FUNC_WHATISMYIP_STRING_E)_FUNC_WHATISMYIP_STRING_E=qbs_new(0,0);
    qbs *_FUNC_WHATISMYIP_STRING_URL3=NULL;
    if (!_FUNC_WHATISMYIP_STRING_URL3)_FUNC_WHATISMYIP_STRING_URL3=qbs_new(0,0);
    byte_element_struct *byte_element_20=NULL;
    if (!byte_element_20){
    if ((mem_static_pointer+=12)<mem_static_limit) byte_element_20=(byte_element_struct*)(mem_static_pointer-12); else byte_element_20=(byte_element_struct*)mem_static_malloc(12);
    }
    qbs *_FUNC_WHATISMYIP_STRING_X=NULL;
    if (!_FUNC_WHATISMYIP_STRING_X)_FUNC_WHATISMYIP_STRING_X=qbs_new(0,0);
    byte_element_struct *byte_element_21=NULL;
    if (!byte_element_21){
    if ((mem_static_pointer+=12)<mem_static_limit) byte_element_21=(byte_element_struct*)(mem_static_pointer-12); else byte_element_21=(byte_element_struct*)mem_static_malloc(12);
    }
    float *_FUNC_WHATISMYIP_SINGLE_T=NULL;
    if(_FUNC_WHATISMYIP_SINGLE_T==NULL){
    _FUNC_WHATISMYIP_SINGLE_T=(float*)mem_static_malloc(4);
    *_FUNC_WHATISMYIP_SINGLE_T=0;
    }
    qbs *_FUNC_WHATISMYIP_STRING_A2=NULL;
    if (!_FUNC_WHATISMYIP_STRING_A2)_FUNC_WHATISMYIP_STRING_A2=qbs_new(0,0);
    qbs *_FUNC_WHATISMYIP_STRING_A=NULL;
    if (!_FUNC_WHATISMYIP_STRING_A)_FUNC_WHATISMYIP_STRING_A=qbs_new(0,0);
    float *_FUNC_WHATISMYIP_SINGLE_I=NULL;
    if(_FUNC_WHATISMYIP_SINGLE_I==NULL){
    _FUNC_WHATISMYIP_SINGLE_I=(float*)mem_static_malloc(4);
    *_FUNC_WHATISMYIP_SINGLE_I=0;
    }
    float *_FUNC_WHATISMYIP_SINGLE_I2=NULL;
    if(_FUNC_WHATISMYIP_SINGLE_I2==NULL){
    _FUNC_WHATISMYIP_SINGLE_I2=(float*)mem_static_malloc(4);
    *_FUNC_WHATISMYIP_SINGLE_I2=0;
    }
    float *_FUNC_WHATISMYIP_SINGLE_L=NULL;
    if(_FUNC_WHATISMYIP_SINGLE_L==NULL){
    _FUNC_WHATISMYIP_SINGLE_L=(float*)mem_static_malloc(4);
    *_FUNC_WHATISMYIP_SINGLE_L=0;
    }
    float *_FUNC_WHATISMYIP_SINGLE_I3=NULL;
    if(_FUNC_WHATISMYIP_SINGLE_I3==NULL){
    _FUNC_WHATISMYIP_SINGLE_I3=(float*)mem_static_malloc(4);
    *_FUNC_WHATISMYIP_SINGLE_I3=0;
    }
    byte_element_struct *byte_element_23=NULL;
    if (!byte_element_23){
    if ((mem_static_pointer+=12)<mem_static_limit) byte_element_23=(byte_element_struct*)(mem_static_pointer-12); else byte_element_23=(byte_element_struct*)mem_static_malloc(12);
    }
    qbs *_FUNC_WHATISMYIP_STRING_D=NULL;
    if (!_FUNC_WHATISMYIP_STRING_D)_FUNC_WHATISMYIP_STRING_D=qbs_new(0,0);
    double fornext_value25;
    double fornext_finalvalue25;
    double fornext_step25;
    uint8 fornext_step_negative25;
    byte_element_struct *byte_element_26=NULL;
    if (!byte_element_26){
    if ((mem_static_pointer+=12)<mem_static_limit) byte_element_26=(byte_element_struct*)(mem_static_pointer-12); else byte_element_26=(byte_element_struct*)mem_static_malloc(12);
    }
    byte_element_struct *byte_element_27=NULL;
    if (!byte_element_27){
    if ((mem_static_pointer+=12)<mem_static_limit) byte_element_27=(byte_element_struct*)(mem_static_pointer-12); else byte_element_27=(byte_element_struct*)mem_static_malloc(12);
    }


    mem_lock *sf_mem_lock;
    new_mem_lock();
    sf_mem_lock=mem_lock_tmp;
    sf_mem_lock->type=3;
    if (new_error) goto exit_subfunc;
    qbs_set(_FUNC_WHATISMYIP_STRING_URL,qbs_new_txt_len("www.qb64.org/ip.php",19));
    qbs_cleanup(qbs_tmp_base,0);
    qbs_set(_FUNC_WHATISMYIP_STRING_URL2,_FUNC_WHATISMYIP_STRING_URL);
    qbs_cleanup(qbs_tmp_base,0);
    *_FUNC_WHATISMYIP_SINGLE_X=func_instr(NULL,_FUNC_WHATISMYIP_STRING_URL2,qbs_new_txt_len("/",1),0);
    qbs_cleanup(qbs_tmp_base,0);
    if ((*_FUNC_WHATISMYIP_SINGLE_X)||new_error){
    qbs_set(_FUNC_WHATISMYIP_STRING_URL2,qbs_left(_FUNC_WHATISMYIP_STRING_URL,qbr(*_FUNC_WHATISMYIP_SINGLE_X- 1 )));
    qbs_cleanup(qbs_tmp_base,0);
    }
    *_FUNC_WHATISMYIP_SINGLE_CLIENT=func__openclient(qbs_add(qbs_new_txt_len("TCP/IP:80:",10),_FUNC_WHATISMYIP_STRING_URL2));
    qbs_cleanup(qbs_tmp_base,0);
    if ((-(*_FUNC_WHATISMYIP_SINGLE_CLIENT== 0 ))||new_error){
    goto exit_subfunc;
    }
    qbs_set(_FUNC_WHATISMYIP_STRING_E,qbs_add(func_chr( 13 ),func_chr( 10 )));
    qbs_cleanup(qbs_tmp_base,0);
    qbs_set(_FUNC_WHATISMYIP_STRING_URL3,qbs_right(_FUNC_WHATISMYIP_STRING_URL,qbr(_FUNC_WHATISMYIP_STRING_URL->len-*_FUNC_WHATISMYIP_SINGLE_X+ 1 )));
    qbs_cleanup(qbs_tmp_base,0);
    qbs_set(_FUNC_WHATISMYIP_STRING_X,qbs_add(qbs_add(qbs_add(qbs_new_txt_len("GET ",4),_FUNC_WHATISMYIP_STRING_URL3),qbs_new_txt_len(" HTTP/1.1",9)),_FUNC_WHATISMYIP_STRING_E));
    qbs_cleanup(qbs_tmp_base,0);
    qbs_set(_FUNC_WHATISMYIP_STRING_X,qbs_add(qbs_add(qbs_add(qbs_add(_FUNC_WHATISMYIP_STRING_X,qbs_new_txt_len("Host: ",6)),_FUNC_WHATISMYIP_STRING_URL2),_FUNC_WHATISMYIP_STRING_E),_FUNC_WHATISMYIP_STRING_E));
    qbs_cleanup(qbs_tmp_base,0);
    sub_put2(qbr(*_FUNC_WHATISMYIP_SINGLE_CLIENT),NULL,byte_element((uint64)_FUNC_WHATISMYIP_STRING_X->chr,_FUNC_WHATISMYIP_STRING_X->len,byte_element_21),0);
    qbs_cleanup(qbs_tmp_base,0);
    *_FUNC_WHATISMYIP_SINGLE_T=func_timer(NULL,0);
    do{
    sub__delay( 0.05E+0 );
    sub_get2(qbr(*_FUNC_WHATISMYIP_SINGLE_CLIENT),NULL,_FUNC_WHATISMYIP_STRING_A2,0);
    qbs_cleanup(qbs_tmp_base,0);
    qbs_set(_FUNC_WHATISMYIP_STRING_A,qbs_add(_FUNC_WHATISMYIP_STRING_A,_FUNC_WHATISMYIP_STRING_A2));
    qbs_cleanup(qbs_tmp_base,0);
    *_FUNC_WHATISMYIP_SINGLE_I=func_instr(NULL,_FUNC_WHATISMYIP_STRING_A,qbs_new_txt_len("Content-Length:",15),0);
    qbs_cleanup(qbs_tmp_base,0);
    if ((*_FUNC_WHATISMYIP_SINGLE_I)||new_error){
    *_FUNC_WHATISMYIP_SINGLE_I2=func_instr(qbr(*_FUNC_WHATISMYIP_SINGLE_I),_FUNC_WHATISMYIP_STRING_A,_FUNC_WHATISMYIP_STRING_E,1);
    qbs_cleanup(qbs_tmp_base,0);
    if ((*_FUNC_WHATISMYIP_SINGLE_I2)||new_error){
    *_FUNC_WHATISMYIP_SINGLE_L=func_val(func_mid(_FUNC_WHATISMYIP_STRING_A,qbr(*_FUNC_WHATISMYIP_SINGLE_I+ 15 ),qbr(*_FUNC_WHATISMYIP_SINGLE_I2-*_FUNC_WHATISMYIP_SINGLE_I- 14 ),1));
    qbs_cleanup(qbs_tmp_base,0);
    *_FUNC_WHATISMYIP_SINGLE_I3=func_instr(qbr(*_FUNC_WHATISMYIP_SINGLE_I2),_FUNC_WHATISMYIP_STRING_A,qbs_add(_FUNC_WHATISMYIP_STRING_E,_FUNC_WHATISMYIP_STRING_E),1);
    qbs_cleanup(qbs_tmp_base,0);
    if ((*_FUNC_WHATISMYIP_SINGLE_I3)||new_error){
    *_FUNC_WHATISMYIP_SINGLE_I3=*_FUNC_WHATISMYIP_SINGLE_I3+ 4 ;
    if ((qbs_cleanup(qbs_tmp_base,-(((float)((_FUNC_WHATISMYIP_STRING_A->len-*_FUNC_WHATISMYIP_SINGLE_I3+ 1 )))==((float)(*_FUNC_WHATISMYIP_SINGLE_L)))))||new_error){
    sub_close(qbr(*_FUNC_WHATISMYIP_SINGLE_CLIENT),1);
    qbs_set(_FUNC_WHATISMYIP_STRING_D,func_mid(_FUNC_WHATISMYIP_STRING_A,qbr(*_FUNC_WHATISMYIP_SINGLE_I3),qbr(*_FUNC_WHATISMYIP_SINGLE_L),1));
    qbs_cleanup(qbs_tmp_base,0);
    *_FUNC_WHATISMYIP_SINGLE_I= 0 ;
    qbs_set(_FUNC_WHATISMYIP_STRING_X,qbs_new_txt_len("",0));
    qbs_cleanup(qbs_tmp_base,0);
    fornext_value25= 1 ;
    fornext_finalvalue25=_FUNC_WHATISMYIP_STRING_D->len;
    fornext_step25= 1 ;
    if (fornext_step25<0) fornext_step_negative25=1; else fornext_step_negative25=0;
    if (new_error) goto fornext_error25;
    goto fornext_entrylabel25;
    while(1){
    fornext_value25=fornext_step25+(*_FUNC_WHATISMYIP_SINGLE_I2);
    fornext_entrylabel25:
    *_FUNC_WHATISMYIP_SINGLE_I2=fornext_value25;
    qbs_cleanup(qbs_tmp_base,0);
    if (fornext_step_negative25){
    if (fornext_value25<fornext_finalvalue25) break;
    }else{
    if (fornext_value25>fornext_finalvalue25) break;
    }
    fornext_error25:;
    if ((qbs_cleanup(qbs_tmp_base,-(qbs_asc(_FUNC_WHATISMYIP_STRING_D,qbr(*_FUNC_WHATISMYIP_SINGLE_I2))== 46 )))||new_error){
    if ((qbs_cleanup(qbs_tmp_base,-(_FUNC_WHATISMYIP_STRING_X->len== 0 )))||new_error){
    goto exit_subfunc;
    }
    qbs_set(_FUNC_WHATISMYIP_STRING_X,qbs_new_txt_len("",0));
    qbs_cleanup(qbs_tmp_base,0);
    *_FUNC_WHATISMYIP_SINGLE_I=*_FUNC_WHATISMYIP_SINGLE_I+ 1 ;
    if ((-(*_FUNC_WHATISMYIP_SINGLE_I> 3 ))||new_error){
    goto exit_subfunc;
    }
    }else{
    if (qbs_cleanup(qbs_tmp_base,(-(qbs_asc(_FUNC_WHATISMYIP_STRING_D,qbr(*_FUNC_WHATISMYIP_SINGLE_I2))< 48 ))|(-(qbs_asc(_FUNC_WHATISMYIP_STRING_D,qbr(*_FUNC_WHATISMYIP_SINGLE_I2))> 57 )))){
    goto exit_subfunc;
    }else{
    qbs_set(_FUNC_WHATISMYIP_STRING_X,qbs_add(_FUNC_WHATISMYIP_STRING_X,func_mid(_FUNC_WHATISMYIP_STRING_D,qbr(*_FUNC_WHATISMYIP_SINGLE_I2), 1 ,1)));
    qbs_cleanup(qbs_tmp_base,0);
    }
    }
    fornext_continue_24:;
    }
    fornext_exit_24:;
    qbs_set(_FUNC_WHATISMYIP_STRING_WHATISMYIP,_FUNC_WHATISMYIP_STRING_D);
    qbs_cleanup(qbs_tmp_base,0);
    goto exit_subfunc;
    }
    }
    }
    }
    dl_continue_22:;
    }while((!(-(((float)((func_timer(NULL,0))))>((float)((*_FUNC_WHATISMYIP_SINGLE_T+ 5 ))))))&&(!new_error));
    dl_exit_22:;
    sub_close(qbr(*_FUNC_WHATISMYIP_SINGLE_CLIENT),1);
    exit_subfunc:;
    free_mem_lock(sf_mem_lock);

    
    //"free1.txt"
    qbs_free(_FUNC_WHATISMYIP_STRING_URL);
    qbs_free(_FUNC_WHATISMYIP_STRING_URL2);
    qbs_free(_FUNC_WHATISMYIP_STRING_E);
    qbs_free(_FUNC_WHATISMYIP_STRING_URL3);
    qbs_free(_FUNC_WHATISMYIP_STRING_X);
    qbs_free(_FUNC_WHATISMYIP_STRING_A2);
    qbs_free(_FUNC_WHATISMYIP_STRING_A);
    qbs_free(_FUNC_WHATISMYIP_STRING_D);


    if ((tmp_mem_static_pointer>=mem_static)&&(tmp_mem_static_pointer<=mem_static_limit)) mem_static_pointer=tmp_mem_static_pointer; else mem_static_pointer=mem_static;
    cmem_sp=tmp_cmem_sp;
    qbs_maketmp(_FUNC_WHATISMYIP_STRING_WHATISMYIP);return _FUNC_WHATISMYIP_STRING_WHATISMYIP;
}
