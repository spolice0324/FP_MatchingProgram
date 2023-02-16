# FP_MatchingProgram
슈프리마ID 동계 인턴 실습 - 자사 SDK를 이용한 지문인식 및 매칭 프로그램 데모 구현

인턴실습 기간 (2023. 1. 2 ~ 2023. 2. 28)

프로그램 구현 기간 (2023. 1. 4 ~ 2023. 2. 16) 

### 완성된 데모프로그램 기능 소개 및 정리

**Practice_biomini란?**

Suprema ID의 스캐너 biomini 제품을 이용하여 지문을 스캔하고 이를 활용한 이미지 캡처, 데이터 추출, 지문 대조, 확인 결과 값 도출 등의 기능을 사용할 수 있는 프로그램을 데모로 제작하였다. 

### 1. 프로그램 Dialog 모습

![image](https://user-images.githubusercontent.com/82880442/219286159-6c3e22eb-fa58-4626-97b0-7143ce65de20.png)

 

### 2. 기능 소개

**1) Init**  

![image](https://user-images.githubusercontent.com/82880442/219286230-da0fd01c-7a23-4955-a903-750483b8f0f0.png)

USB로 연결하여 인식된 기기가 있는지 확인하고 있다면 연결합니다. 

**2) Get Scanner Handle**

![image](https://user-images.githubusercontent.com/82880442/219286266-8f190e23-d560-4f1f-8b73-eb150e075946.png)

기기 등록을 성공했다면 Get Sxanner Handle을  통해 디바이스를 가져옵니다.  스캐너의 제품, 버전 등을 확인하고 가져옵니다. 

**3) Capture Single Image** 

![image](https://user-images.githubusercontent.com/82880442/219286309-7bdbc85b-3646-45e5-ac60-6d3ff1c62b0e.png)

버튼을 클릭하고 기기에 손가락을 스캔합니다. 지문인식이 성공한다면 이 이미지를 다이얼로그에 띄웁니다. 

**4) Extract**

![image](https://user-images.githubusercontent.com/82880442/219286338-c9f6c7fe-3b4e-46ca-bdae-c7a5768e8d26.png)

![image](https://user-images.githubusercontent.com/82880442/219286370-ddaf3459-f686-4b5b-9a97-3a6ff3c7a2ec.png)

Extract 는 캡처한 지문 이미지에서 신원을 확인할 수 있는 특징점들을 추출합니다. 

**5) Verify**

![image](https://user-images.githubusercontent.com/82880442/219286408-6a72e54e-0b52-404d-bbc3-4bc77b7e7416.png)
Verify를 클릭하면 Caputre Image 와 같은 동작이 발생합니다.  지문 캡처에 성공하면 방금 캡처했던 지문과 이전 캡처했던 지문을 모두 Extract하고 특징점을 분석하여 동일한 지문을 인식하였는지 확인합니다. 이 기능을 통해 본인 인증, 본인 식별이 필요한 작업을 수행할 수 있습니다. 

이 프로그램에서는 두 지문 대조가 성공하면 Success 메시지를, 실패하면 Fail 메세지를 edit box에 출력합니다. 

**6) Load BMP and Get LFD** 

![image](https://user-images.githubusercontent.com/82880442/219286450-1da63132-5109-4423-bcf8-fdc5ca507a38.png)


Load BMP and Get LFD를 통해 이미지 분석이 가능합니다. 이 버튼 박스를 클릭하면 파일 다이얼로그가 뜨면서 이미지를 불러올 수 있게 됩니다. 

여러장 선택도 가능하며 LFD 스코어를 얻어낼 수 있는 디바이스를 연결했다면, LFD 점수를 받을 수 있습니다.

***LFD란 ? (Live Finger Detect)**

슈프리마의 살아있는 손가락 감지(LFD) 기술은 위조 손가락의 동적 및 정적 이미지 특성 분석과 실제 손가락과 어떻게 구별할 수 있는 지를 기반으로 합니다. 지문 이미지의 동적으로 변화하는 패턴의 이상과 손가락의 생동감 또는 부자연스러움과 같은 몇 가지 정적 특징을 감지하는 고급 분석 알고리즘을 통해 위조 손가락과 실제 손가락을 명확하게 구분합니다.

![image](https://user-images.githubusercontent.com/82880442/219286511-f2ad587b-fa25-4989-b2de-038074e490a2.png)

**7) Save Template**

![image](https://user-images.githubusercontent.com/82880442/219286545-b2ca4c4b-a724-4bf3-91ad-a2450083d076.png)
Capture Singe Image → Extract 를 하여 특징점을 추출한 데이터가 있다면 이 데이터를 저장할 bin 확장자형태의 템플릿 파일을 생성할 수 있습니다. 

소스코드에서 파일의 절대 경로를 입력하여 저장 경로를 설정하였기에 이 경로를 바꿔주면 원하는 위치에 파일을 저장할 수 있는 형태입니다. 

**8) Open File1 과 Open File2**

![image](https://user-images.githubusercontent.com/82880442/219286575-8a8155a0-f21c-42f8-93e4-453a6d39cf86.png)
지금까지는 직접 이미지를 캡처하거나 이미지를 불러오는 기능을 구현했습니다. 지금부터는 이미 저장되어있는 템플릿 파일들을 이용하여 할 수 있는 기능입니다. 

Open File 1과 Open File 2는 각각 비교하고자 하는 파일들을 폴더의 경로를 통해 불러오는 기능입니다. 두 폴더에 있는 파일들을 비교하는 기능을 실행할 수 있도록 불러오는 버튼 박스입니다.  

현재 edit box에는 읽어온 파일의 개수만큼 ‘파일 이름 읽어오기 성공‘ 메세지를 출력하고 있습니다.

**9) Match** 

![image](https://user-images.githubusercontent.com/82880442/219286629-0ea3e1a2-457e-4fba-87d3-56cc3faebedb.png)
![image](https://user-images.githubusercontent.com/82880442/219286652-f62b2551-2062-4c72-8560-efdef45b065f.png)
Match는 Open File1 과 Open File2 를 통해 불러온 각각의 파일들끼리 Verify를 진행합니다.

확인 결과를 edit box에 출력합니다. 

**10) Select1 과 Select2**

![image](https://user-images.githubusercontent.com/82880442/219286674-09ef79b4-7998-4823-9855-ebac4762bc56.png)
Select1과 Select2는 각각 Open1, Open2에 있는 파일들의 정보를 불러오는 역할입니다. 

matching score를 얻고 이 결과를 분류하는 기능을 사용하기 위해 파일명에 담긴 정보를 파싱하고 분류에 활용합니다. 

Open File1 , Open File2 → Select1, Select2 → Genuine, Imposter 분류 결과 파일 생성 순으로 진행합니다.

**11) Genuine, Imposter 분류 결과 파일 생성**

![image](https://user-images.githubusercontent.com/82880442/219286702-6af15ba8-6205-495f-84bc-e0e207de4678.png)

![image](https://user-images.githubusercontent.com/82880442/219286737-ebe3eb0c-c15e-451f-a6eb-a3cf1da1d49d.png)
![image](https://user-images.githubusercontent.com/82880442/219286792-9c030749-5808-4887-ba99-d793687ff46e.png)
이 버튼 박스를 클릭하면 Open1과 Open2 에서 열었던 폴더에 저장되있는 파일들끼리 verify , matching 을 진행합니다. 그리고 파일들의 정보를 바탕으로 Geunine Matching Score, Imposter Matching Sccore를 정리할 수 있습니다. 그 결과를 txt 파일로 저장할 수 있도록 파일을 생성하고 파일을 씁니다. 

![image](https://user-images.githubusercontent.com/82880442/219286822-d8262eb1-367e-4b35-ab39-82f5abd0b04f.png)
위와같이 매칭 결과를 확인할 수 있습니다. 

이 때 두 폴더 안에 있는 파일 중 같은 파일은 제외하고, Genuine Matching인지, Imposter Matching 인지를 구분하고 분류하여 텍스트를 작성합니다. 

- **Genuine 매칭과 Imposter 매칭**
    
    인식 정확도 측정을 위해 **동일 인물의 손가락 영상 간 매칭(genuine matching)** 유사도와 **다른 인물의 손가락 영상 간 매칭(imposter)** 유사도를  측정을 의미한다. 
    
    측정한 유사도 값에 대한 확률밀도함수를 획득하여 유사도의 임계치에 따른 오수락율(FAR: False Acceptance Rate)과 오거부율 (FRR: False Rejection Rate)이 최소가 되는, 즉 FAR과 FRR이 동일하게 나타나는 동일오류율(EER: Equal Error Rate) 지점을 베이시안 최소오류 결정이론에 근거하여 계산한다. 
    
    **오수락율**은 바이오 인식 시스템이 **인증하려는 사용자와 등록된 사용자가 다름에도 불구하고 동일한 사용자로 잘못 인식하여 타인을 수락하는 오류의 비율**이고, **오거부율**은 **사용자와 등록된 사용자가 동일임에도 불구하고 다른 사용자로 잘못 인식하여 본인을 거부하는 오류의 비율**을 의미한다. EER은 바이오 인식 시스템의 성능 지표로서 오수락률(FAR)과 오거부율(FRR)이 동일하게 나타나는 지점이 **최소오류 지점이라는 이론에 근거**한 성능 지표이다.
