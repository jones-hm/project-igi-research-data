Project I.G.I 1 Graph Structure of Vertex,Edges and other data. (IGI Структура графа). 
*Research followed of Dimon Krevedko,Yoejin Light,Artiom Rotari and continued by (IGI ResearchDevs@HM)
* If you want to use this data respect fellow researchers and give proper credits to people. (давать людям должные кредиты)
* Yoejin Light - https://vk.com/id436486682
* Dimon Krevedko - https://vk.com/dimonkrevedko
* Artiom Rotari - https://github.com/NEWME0
* IGI ResearchDevs@HM - https://vk.com/id679925339


STATIC ANALYSIS SECTION - (РАЗДЕЛ СТАТИЧЕСКОГО АНАЛИЗА)
* Graph Hex Signatures on file `graphs.dat`
* Here all data could be found at static index i.e [current_index + 8] 
* example Node Material '0429' index is 20 then [20 + 8] = 28, Read DataType of 4 or 8 Bytes.

| S.No | Graph Item          | Signature | Hex Bytes | Data-Type |
|------|---------------------|-----------|-----------|-----------|
| 1    | Max Nodes           | 04E6      | 04E63A0D  | Integer   |
| 2    | Node Id             | 04CE      | 04CE3507  | Integer   |
| 3    | Node Position       | 0495      | 0495421D  | Real64x3  |
| 4    | Node Gamma          | 049C      | 049C7E0F  | Single    |
| 5    | Node Radius         | 0423      | 04233014  | Single    |
| 6    | Node Material       | 0429      | 0429B61B  | Integer   |
| 7    | Node Criteria       | 04E5      | 04E5D31B  | Stringx18 |
| 8    | Node Edge(Link1)    | 044A      | 044A1009  | Integer   |
| 9    | Node Edge(Link2)    | 04F6      | 04F61809  | Integer   |
| 10   | Node Edge(LinkType) | 0423      | 0423A90D  | Integer   |




RUNTIME ANALYSIS SECTION - (РАЗДЕЛ АНАЛИЗА РАБОТЫ)
* Graph Nodes data sequence extracted by IDA/Ghidra. (обратный инжиниринг)
* Sub = Game sub routine(Method) to extract the data.
* Sub_004FAEE0 here`004FAEE0` is actual address of this game method.
* Game variables prefix this is Hungarian notation in C++ game engine 'nMaxNodes' here n = `Number/Int`, v = `Vector/Float`, e = `Enum/String`, t = `Struct/Type`


| S.No | Node Type       | Method Sub     |
|------|-----------------|----------------|
| 1    | nMaxNodes     | SUB_004FAEE0() |
| 2    | nNodeID       | SUB_004FAF50() |
| 3    | tNodePosition | SUB_004FAF80() |
| 4    | vNodeGamma    | SUB_004FAFA0() |
| 5    | vNodeRadius   | SUB_004FAFC0() |
| 6    | nNodeMaterial | SUB_004FAFE0() |
| 7    | nNodeCriteria | SUB_004FB030() |
| 8    | nLinkID1      | SUB_004FB080() |
| 9    | nLinkID2      | SUB_004FB0B0() |
| 10   | eLinkType     | SUB_004FB0D0() |


- Graph Misc Data.
- Contains various misc data from Static and Runtime analysis.
Graph signature Hex Bytes = 'CC DD EE FF'
Node size elements = 0xA77247

- Node Criteria constants.
* NODECRITERIA_DOOR = 1
* NODECRITERIA_VIEW = 2
* NODECRITERIA_STAIR = 4



