#프로그래머스_해시_위장_42578
#파이썬은 내장함수로 해시를 제공함
def solution(clothes):
    ##해시는 주소로 그 값에 접근을 하는 것이므로 주소의 범위를 0~1150000까지 잡음
    num=[0 for i in range(1150000)]
    #곱셈을 위해 반환하는 answer 값 1로 설정
    answer = 1

    for js in clothes:
        #옷 종류를 받아서 그 종류가 가리키는 해시값의 주소를 1씩 증가
        num[hash(js[1])%1150000]+=1

    #다시 반복하면서 옷 종류의 주소값을 재탐색
    for js in clothes:
        #주소값을 통해 탐색한 수에 해당하는 것은 특정 종류의 옷의 개수를 의미함
        if num[hash(js[1])%1150000]>0:
            #옷의 종류 중 하나를 선택한다+선택하지 않는다의 경우가 있음
            #이를 answer 값에 곱함
            answer*= (num[hash(js[1])%1150000]+1)
            
            #선택했기에 초기화
            num[hash(js[1])%1150000]=0
    #아예선택 안하는 경우도 있으므로 1을 빼줌      
    return answer-1
