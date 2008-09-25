topic "One";
[2 $$0,0#00000000000000000000000000000000:Default]
[i448;a25;kKO9;2 $$1,0#37138531426314131252341829483380:class]
[l288;2 $$2,0#27521748481378242620020725143825:desc]
[0 $$3,0#96390100711032703541132217272105:end]
[H6;0 $$4,0#05600065144404261032431302351956:begin]
[i448;a25;kKO9;2 $$5,0#37138531426314131252341829483370:item]
[l288;a4;*@5;1 $$6,6#70004532496200323422659154056402:requirement]
[l288;i1121;b17;O9;~~~.1408;2 $$7,0#10431211400427159095818037425705:param]
[i448;b42;O9;2 $$8,8#61672508125594000341940100500538:tparam]
[b42;2 $$9,9#13035079074754324216151401829390:normal]
[{_} 
[s0;:noref: [@(0.0.255) template]_<[@(0.0.255) class]_[*@4 T][@(0.0.255) >]&]
[s1;:`:`:One`:`:class: [@(0.0.255) class]_[* One]_:_[@(0.0.255) private]_[*@3 MoveableAndDeepC
opyOption][@(0.0.255) <]_[* One][@(0.0.255) <][*@4 T][@(0.0.255) >]_>_&]
[s0;*C@4 &]
[s8;%% [%-*C@4 T]-|Type or base class of element stored in One.&]
[s0;%% &]
[s0;%% One is a container capable of containing none or single element 
of type specified as template argument or derived from it.&]
[s0;%% One is [*/^topic`:`/`/Core`/srcdoc`/Moveable`$en`-us^ moveable][*/  
]type with [*/^topic`:`/`/Core`/srcdoc`/pick`_`$en`-us^ pick and 
optional deep copy] transfer semantics. Calling methods of picked 
One is logic error with exception of&]
[s0;%% [C+75 void ][*C+75 operator`=][C+75 (pick`_ One`& ][*C@3+75 v][C+75 )]&]
[s0;%% [C+75 void ][*C+75 operator<<`=][C+75 (const One`& ][*C@3+75 v][C+75 )][+75  
][/+75 (defined using DeepCopyOption template base class)]&]
[s3; &]
[s4; &]
[s5;:`:`:One`:`:Clear`(`): [@(0.0.255) void]_[* Clear]()&]
[s2; Removes the element stored in One.&]
[s3; &]
[s4; &]
[s5;:`:`:One`:`:IsPicked`(`)const: [@(0.0.255) bool]_[* IsPicked]()_[@(0.0.255) const]&]
[s2;%% Members&]
[s3; &]
[s4; &]
[s5;:`:`:One`:`:One`(`): [* One]()&]
[s2;%% Default constructor. Constructs empty One.&]
[s3; &]
[s4; &]
[s5;:`:`:One`:`:One`(T`*`): [* One]([*@4 T]_`*[*@3 newt])&]
[s2;%% Constructs One with content. Content is specified by pointer 
to object created using operator new. One takes over ownership 
of this this object. &]
[s7;%% [*C@3 newt]-|Object to be added.&]
[s3; &]
[s4; &]
[s5;:`:`:One`:`:One`(pick`_`:`:One`<T`>`&`): [* One]([@(0.128.128) pick`_]_[* One][@(0.0.255) <
][*@4 T][@(0.0.255) >`&]_[*@3 p])&]
[s2;%% Pick constructor. Transfers source One in low constant time, 
but destroys it by picking. &]
[s7;%% [*C@3 p]-|Source One.&]
[s3; &]
[s4; &]
[s5;:`:`:One`:`:One`(const`:`:One`<T`>`&`,int`): [* One]([@(0.0.255) const]_[* One][@(0.0.255) <
][*@4 T][@(0.0.255) >`&]_[*@3 p], [@(0.0.255) int])&]
[s2;%% Optional deep copy constructor.&]
[s6;%% Requires T to have deep copy constructor or optional deep 
copy constructor.&]
[s7;%% [*C@3 p]-|Source One.&]
[s3; &]
[s4; &]
[s5;:`:`:One`:`:`~One`(`): [@(0.0.255) `~][* One]()&]
[s2;%% Destructor.&]
[s3; &]
[s4; &]
[s5;:`:`:One`:`:Attach`(T`*`): [@(0.0.255) void]_[* Attach]([*@4 T]_`*[*@3 data])&]
[s2;%% Assigns element to One. (Note: if there is content in One while 
calling this function, it is destroyed).&]
[s7;%% [%-*C@3 data]-|Pointer to the new element created using operator 
new.&]
[s3; &]
[s4; &]
[s5;:`:`:One`:`:Detach`(`)pick`_: [*@4 T]_`*[* Detach]()_[@(0.128.128) pick`_]&]
[s2;%% Removes content giving up ownership. Client is responsible 
for deletion of content.&]
[s7;%% [*/ Return value]-|Pointer to the content allocated on the heap.&]
[s3; &]
[s4; &]
[s5;:`:`:One`:`:operator`-`(`)pick`_: [*@4 T]_`*[* operator`-]()_[@(0.128.128) pick`_]&]
[s2;%% Same as Detach() (operator version).&]
[s7;%% [*/ Return value]-|Pointer to the content allocated on the heap.&]
[s3; &]
[s4; &]
[s5;:`:`:One`:`:Clear`(`): [@(0.0.255) void]_[* Clear]()&]
[s2;%% Removes and destroys content.&]
[s3; &]
[s4; &]
[s5;:`:`:One`:`:operator`=`(T`*`): [@(0.0.255) void]_[* operator`=]([*@4 T]_`*[*@3 data])&]
[s2;%% Same as Attach(data) (operator version).&]
[s7;%% [%-*C@3 data]-|Pointer to the new element created using operator 
new.&]
[s3; &]
[s4; &]
[s5;:`:`:One`:`:operator`=`(pick`_`:`:One`<T`>`&`): [@(0.0.255) void]_[* operator`=]([@(0.128.128) p
ick`_]_[_^`:`:One^ One][@(0.0.255) <][*@4 T][@(0.0.255) >`&]_[*@3 d])&]
[s2;%% Pick operator. Transfers source One in low constant time, 
but destroys it by picking.&]
[s7;%% [%-*C@3 d]-|Source One.&]
[s3; &]
[s4; &]
[s5;:`:`:One`:`:operator`-`>`(`)const: [@(0.0.255) const]_[*@4 T]_`*[* operator`->]()_[@(0.0.255) c
onst]&]
[s2;%% Constant content access operator. Illegal if there is no content.&]
[s7;%% [*/ Return value]-|Returns constant pointer to content.&]
[s3; &]
[s4; &]
[s5;:`:`:One`:`:operator`-`>`(`): [*@4 T]_`*[* operator`->]()&]
[s2;%% Content access operator. Illegal if there is no content.&]
[s7;%% [*/ Return value]-|Returns pointer to content.&]
[s3; &]
[s4; &]
[s5;:`:`:One`:`:operator`~`(`)const: [@(0.0.255) const]_[*@4 T]_`*[* operator`~]()_[@(0.0.255) c
onst]&]
[s2;%% Constant content pointer access.&]
[s7;%% [*/ Return value]-|Returns constant pointer to content or NULL 
when there is no content.&]
[s3; &]
[s4; &]
[s5;:`:`:One`:`:operator`~`(`): [*@4 T]_`*[* operator`~]()&]
[s2;%% Content pointer access.&]
[s7;%% [*/ Return value]-|Returns pointer to content or NULL when there 
is no content.&]
[s3; &]
[s4; &]
[s5;:`:`:One`:`:operator`*`(`)const: [@(0.0.255) const]_[*@4 T][@(0.0.255) `&]_[* operator`*](
)_[@(0.0.255) const]&]
[s2;%% Content constant reference access. Illegal if there is no 
content.&]
[s7;%% [*/ Return value]-|Constant reference to content.&]
[s3; &]
[s4; &]
[s5;:`:`:One`:`:operator`*`(`): [*@4 T][@(0.0.255) `&]_[* operator`*]()&]
[s2;%% Content reference access. Illegal if there is no content.&]
[s7;%% [*/ Return value]-|Reference to content.&]
[s3; &]
[s4; &]
[s5;:`:`:One`:`:Create`(`): [@(0.0.255) template]_<[@(0.0.255) class]_[*@4 TT][@(0.0.255) >]_
[*@4 TT][@(0.0.255) `&]_[* Create]()&]
[s2;%% Creates content in One. (Note: if there is content in One while 
calling this function, it is destroyed).&]
[s7;%% [*C@4 TT]-|Type of content. Must be equal to T or derived from 
it.&]
[s7;%% [*/ Return value]-|Reference to actual content (of type TT).&]
[s3; &]
[s4; &]
[s5;:`:`:One`:`:IsPicked`(`)const: [@(0.0.255) bool]_[* IsPicked]()_[@(0.0.255) const]&]
[s7;%% [*/ Return value]-|true if One is picked.&]
[s3; &]
[s4; &]
[s5;:`:`:One`:`:IsEmpty`(`)const: [@(0.0.255) bool]_[* IsEmpty]()_[@(0.0.255) const]&]
[s7;%% [*/ Return value]-|true if there is no content.&]
[s3; &]
[s4; &]
[s5;:`:`:One`:`:operator bool`(`)const: [@(0.0.255) operator]_[@(0.0.255) bool]()_[@(0.0.255) c
onst]&]
[s7;%% [*/ Return value]-|true if there is content.&]
[s0;%% ]