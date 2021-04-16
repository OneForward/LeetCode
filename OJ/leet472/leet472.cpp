/*
leet472


*/


#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <functional>
#include <utility>
#include "../utils/LeetCpp.utils.hpp"

using namespace std;


struct Trie
{
    Trie* next[26]{};
    string leaf="";
};


class Solution1 {
public:
    vector<string> findAllConcatenatedWordsInADict(const vector<string>& words) {
        Trie* trie = new Trie;
        unordered_set<string_view> S;

        function<bool(const string_view&, int, int&)> dfs = [&](const string_view& word, int start, int& count)->bool {
            if (start == word.size() and count > 1) return true;
            auto node = trie;
            for (int i=start; i < word.size(); ++i) {
                auto ch = word[i];
                if (node->next[ch-'a'] == nullptr) { 
                    return false; 
                }
                node = node->next[ch-'a'];

                if (not node->leaf.empty()) {
                    count++;
                    if (S.count(word.substr(i+1, string_view::npos)) or dfs(word, i+1, count))  
                        return true; 
                    count--;
                }
            }
            return false;
        };

        for (const auto& word: words) {
            auto node = trie;
            for (const auto& ch: word) {
                if (node->next[ch-'a'] == nullptr) node->next[ch-'a'] = new Trie;
                node = node->next[ch-'a'];
            }
            node->leaf = word;
        }

        vector<string> ans;
        for (const auto& word: words) {
            auto count = 0;
            if (dfs(word, 0, count)) ans.push_back(word), S.insert(word);
        }   
        return ans;
    }
};
class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(const vector<string>& _words) {
        unordered_set<string_view> words(_words.begin(), _words.end());
        unordered_set<string_view> S;

        function<bool(const string_view&, int&)> dfs = [&](const string_view& word, int& count)->bool {
            if (count and (words.count(word) or S.count(word))) return true;
            for (int i=0; i < word.size(); ++i) {
                if (words.count(word.substr(0, i))) {
                    count++;
                    if (dfs(word.substr(i, string_view::npos), count)) return true;
                    count--;
                }
            }
            return false;
        };

        vector<string> ans;
        for (const auto& word: _words) {
            auto count = 0;
            if (dfs(word, count)) ans.push_back(word), S.insert(word);
        }   
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.findAllConcatenatedWordsInADict({"cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat" }) << endl;
    cout << sol.findAllConcatenatedWordsInADict({"cat","dog","catdog"}) << endl;
    cout << sol.findAllConcatenatedWordsInADict({"a","aa","aaa"}) << endl;
    // cout << sol.findAllConcatenatedWordsInADict({"rfkqyuqfjkx","","vnrtysfrzrmzl","gfve","qfpd","lqdqrrcrwdnxeuo","q","klaitgdphcspij","hbsfyfv","adzpbfudkklrw","aozmixr","ife","feclhbvfuk","yeqfqojwtw","sileeztxwjl","ngbqqmbxqcqp","khhqr","dwfcayssyoqc","omwufbdfxu","zhift","kczvhsybloet","crfhpxprbsshsjxd","ilebxwbcto","yaxzfbjbkrxi","imqpzwmshlpj","ta","hbuxhwadlpto","eziwkmg","ovqzgdixrpddzp","c","wnqwqecyjyib","jy","mjfqwltvzk","tpvo","phckcyufdqml","lim","lfz","tgygdt","nhcvpf","fbrpzlk","shwywshtdgmb","bkkxcvg","monmwvytby","nuqhmfj","qtg","cwkuzyamnerp","fmwevhwlezo","ye","hbrcewjxvcezi","tiq","tfsrptug","iznorvonzjfea","gama","apwlmbzit","s","hzkosvn","nberblt","kggdgpljfisylt","mf","h","bljvkypcflsaqe","cijcyrgmqirz","iaxakholawoydvch","e","gttxwpuk","jf","xbrtspfttota","sngqvoijxuv","bztvaal","zxbshnrvbykjql","zz","mlvyoshiktodnsjj","qplci","lzqrxl","qxru","ygjtyzleizme","inx","lwhhjwsl","endjvxjyghrveu","phknqtsdtwxcktmw","wsdthzmlmbhjkm","u","pbqurqfxgqlojmws","mowsjvpvhznbsi","hdkbdxqg","ge","pzchrgef","ukmcowoe","nwhpiid","xdnnl","n","yjyssbsoc","cdzcuunkrf","uvouaghhcyvmlk","aajpfpyljt","jpyntsefxi","wjute","y","pbcnmhf","qmmidmvkn","xmywegmtuno","vuzygv","uxtrdsdfzfssmel","odjgdgzfmrazvnd","a","rdkugsbdpawxi","ivd","bbqeonycaegxfj","lrfkraoheucsvpi","eqrswgkaaaohxx","hqjtkqaqh","berbpmglbjipnuj","wogwczlkyrde","aqufowbig","snjniegvdvotu","ocedkt","bbufnxorixibbd","rzuqsyr","qghoy","evcuanuujszitaoa","wsx","glafbwzdd","znrvjqeyqi","npitruijvyllsi","objltu","ryp","nvybsfrxtlfmp","id","zoolzslgd","owijatklvjzscizr","upmsoxftumyxifyu","xucubv","fctkqlroq","zjv","wzi","ppvs","mflvioemycnphfjt","nwedtubynsb","repgcx","gsfomhvpmy","kdohe","tyycsibbeaxn","wjkfvabn","llkmagl","thkglauzgkeuly","paeurdvexqlw","akdt","ihmfrj","janxk","rqdll","cyhbsuxnlftmjc","yybwsjmajbwtuhkk","ovytgaufpjl","iwbnzhybsx","mumbh","jqmdabmyu","br","lwstjkoxbczkj","vhsgzvwiixxaob","fso","qnebmfl","ooetjiz","lq","msxphqdgz","mqhoggvrvjqrp","xbhkkfg","zxjegsyovdrmw","jav","mshoj","ax","biztkfomz","hujdmcyxdqteqja","gqgsomonv","reqqzzpw","lihdnvud","lznfhbaokxvce","fhxbldylqqewdnj","rlbskqgfvn","lfvobeyolyy","v","iwh","fpbuiujlolnjl","gvwxljbo","ypaotdzjxxrsc","mwrvel","umzpnoiei","ogwilaswn","yw","egdgye","hsrznlzrf","mwdgxaigmxpy","yaqgault","dtlg","cyvfiykmkllf","zxqyhvizqmamj","lvvgoifltzywueyp","abinmy","ppzaecvmx","qsmzc","iddymnl","uskihek","evxtehxtbthq","jvtfzddlgch","czohpyewf","ufzazyxtqxcu","brxpfymuvfvs","xrrcfuusicc","aqhlswbzievij","rv","udvmara","upityz","fecd","suxteeitxtg","dfuydrtbfypbn","cypqodxr","wikfuxwjht","jrliuaifpp","vkmxys","wvpfyfpkvgthq","rmajxis","jncxgviyu","av","nmhskodmidaj","lkfrimprrhen","uip","hstyopbvuiqc","p","vwduwmjpblqo","fnxwgqtvwztje","xwnbcuggl","iehimvoymyjasin","spsqiu","flhyfac","mqrbq","pstsxhplrrmbeddv","hnegtuxx","alsyxezjwtlwmxv","jtxytykkcku","bhhlovgcx","xhhivxnutkx","had","aysulvk","m","anhsyxli","jdkgfc","potn","lcibpxkidmwexp","gwoxjicdkv","tltienw","ngiutnuqbzi","o","tzlyb","vumnwehj","os","np","lhv","uzvgyeette","ipfvr","lpprjjalchhhcmh","k","pciulccqssaqgd","tp","dmzdzveslyjad","wtsbhgkd","eouxbldsxzm","vhtonlampljgzyve","xhnlcrldtfthul","xhflc","upgei","rlaks","yfqvnvtnqspyjbxr","phouoyhvls","voibuvbhhjcdflvl","rgorfbjrofokggaf","dqhqats","zchpicyuawpovm","yzwfor","koat","pybf","fhdzsbiyjld","gznfnqydisn","xz","po","tcjup","wygsnxk","kqlima","fgxnuohrnhg","publurhztntgmimc","zuufzphd","iucrmmmjqtcey","wnnbq","rghzyz","ukjqsjbmp","mdtrgv","vyeikgjdnml","kxwldnmi","apzuhsbssaxj","tkbkoljyodlipof","nkq","ktwtj","vgmkgjwle","t","agylw","vomtuy","jbtvitkqn","vtdxwrclpspcn","rdrls","yxfeoh","upj","myctacn","fdnor","ahqghzhoqprgkym","phiuvdv","jp","fdgpouzjwbq","hqoyefmugjvewhxu","qfzwuwe","fnsbijkeepyxry","oja","qthkcij","zpmqfbmnr","ybaibmzonzqlnmd","svo","gjftyfehik","jfrfgznuaytvaegm","aljhrx","odjq","ogwaxrssjxgvnka","zaqswwofedxj","lugpktauixp","dc","odknlbvxrs","jeobu","vqythyvzxbcgrlbg","hwc","erpbaxq","ujxcxck","rrklkb","wlrwyuy","zmg","yyhga","xwdbycdu","htedgvsrhchox","wr","suhesetv","jonqwhkwezjvjgg","sqqyrxtjkcalswq","hvyimhe","pjzdkmoue","zbphmgoxq","lbdlcumdgixjbcq","ztzdjqmadthtdmv","qcagsyqggcf","if","jpjxcjyi","chyicqibxdgkqtg","iwpdklhum","wljmg","micmun","npdbamofynykqv","ijsnfkpfy","lmq","oyjmeqvhcrvgm","mqopusqktdthpvz","fz","r","qbsqtipq","nxtsnason","xbpipyhh","topsuqomfjrd","islif","gbndakaq","bwnkxnwpzeoohlx","hrtbfnq","fguvomeepxoffg","mat","dzfpfnwbfuj","onlvy","cwcchvsasdylb","rxfcztzqopdi","ybrhodjn","oqkijy","ncvrjo","dphbfaal","xgtpdtkz","sebevsopjvciwljf","rcumyacqdapwczen","mabkapuoud","pbozezeygljfftvy","bvazmzbndl","vl","qiaixdtbhqvlzd","ffjfb","svthrfmkoxbho","cvet","ucgqyvopafyttrh","lbgihet","naiqyufxffdw","vruh","uz","ukffmudygjavem","dccamymhp","wofwgjkykm","fbuujzxhln","kmm","lzandlltowjpwsal","fapfvrmezbsjxs","wiw","sc","soqlh","hzaplclkwl","gcdqbcdwbwa","gadgt","pgowefka","juffuguqepwnfh","nbuinl","cpdxf","sox","fq","lfnrhgsxkhx","xrcorfygjxpi","mwtqjwbhgh","loc","fkglorkkvx","nlzdhucvayrz","azefobxutitrf","rlrstkcbtikklmh","ggk","sbphcejuylh","nraoenhd","zngyodiqlchxyycx","rrbhfwohfv","krzolrglgn","cpjesdzy","yoifoyg","hqqevqjugi","ahmv","xgaujnyclcjq","evhyfnlohavrj","byyvhgh","hyw","kedhvwy","ysljsqminajfipds","rglnpxfqwu","cibpynkxg","su","mbntqrlwyampdg","nig","ldhlhqdyjcfhu","jfymrbafmyoc","tyjmnhlfnrtz","dlazixtlxyvm","fbiguhsfuqo","rhymsno","rkbdlchs","ocbbwwd","astaiamnepwkya","mplirup","edkxjq","g","exlwulswtvot","tlnc","vnrrzerz","ygeraoozbtt","yyifkin","eo","ua","qgztvqdolf","rlzddjzcshvd","khxkdxflwxme","kk","zylbhoaac","cw","iizic","gcdxstpz","kjwdqeg","earjrncmmkdel","kbesuhquepj","nrzbllldgdmyrpgl","hllwnqozf","djpchowhwevbqvjj","zsmhylnjpktb","pxnktxkm","fxwiaqqb","qjwufmwresfsfaok","aa","d","iobioqm","svjgzk","khbzp","euexyudhrioi","yqsj","ngrwqpoh","rwuvd","eruffmlg","bxzovyew","faz","pmvfvyguqdi","jlxnoixsy","hyfrdngjf","ly","eibcapetpmeaid","tpnwwiif","pfgsp","kvhhwkzvtvlhhb","pjxurgqbtldims","rncplkeweoirje","akyprzzphew","wyvfpjyglzrmhfqp","ubheeqt","rmbxlcmn","taqakgim","apsbu","khwnykughmwrlk","vtdlzwpbhcsbvjno","tffmjggrmyil","schgwrrzt","mvndmua","nlwpw","glvbtkegzjs","piwllpgnlpcnezqs","xkelind","urtxsezrwz","zechoc","vfaimxrqnyiq","ybugjsblhzfravzn","btgcpqwovwp","zgxgodlhmix","sfzdknoxzassc","wgzvqkxuqrsqxs","dwneyqisozq","fg","vhfsf","uspujvqhydw","eadosqafyxbmzgr","tyff","blolplosqnfcwx","uwkl","puenodlvotb","iizudxqjvfnky","cjcywjkfvukvveq","jrxd","igwb","dftdyelydzyummmt","uvfmaicednym","oai","higfkfavgeemcgo","naefganqo","iqebfibigljbc","ulicojzjfrc","igxprunj","cymbrl","fqmwciqtynca","zjyagi","mzuejrttefhdwqc","zyiurxvf","wrjxffzbjexsh","wrxw","mhrbdxjwi","htknfa","wfrvxqdkhbwwef","vqsghhhutdget","cwupzrts","hbjnb","wpccoa","nx","howbzhaoscgyk","bilt","wqqatye","zceuuwg","jxzon","kkfj","bwsezd","ifdegsyjtswselk","xweimxlnzoh","tqthlftjblnpht","ww","ss","b","jmruuqscwjp","nxbk","wd","cqkrtbxgzg","xhppcjnq","cfq","tkkolzcfi","wblxki","ijeglxsvc","kcqjjwcwuhvzydm","gubqavlqffhrzz","hiwxrgftittd","caybc","ncsyjlzlxyyklc","poxcgnexmaajzuha","dhaccuualacyl","mtkewbprs","oncggqvr","sqqoffmwkplsgbrp","ioajuppvqluhbdet","dzwwzaelmo","afumtqugec","wglucmugwqi","zveswrjevfz","nxlbkak","pzcejvxzeoybb","fd","vewj","ivws","zjhudtpqsfc","zcmukotirrxx","zksmx","umofzhhowyftz","zbotrokaxaryxlk","ueolqk","dxmzhoq","zvu","cjl","esfmqgvxwfy","npbep","vbgjtbv","poeugoqynkbfiv","fewjjscjrei","yqssxzsydgllfzmo","urxkwcypctjkabi","wqtldwhjouas","tovdtkr","onzgeyddkqwuhnim","ffxviyvsktqrfa","qujhd","pvcz","hiyjlkxmeplnrvxg","hdykehkefp","vepcxhozpjxtreyn","liguhuxudbnh","f","ordxzm","klgohcmmbukz","yrmooliaobbnlap","dutnbetocxylcey","ywdsjegd","cr","blbxhjsgcuoxmqft","ngzdc","srfyjjumcbxole","dazwzwtdjoyuqeqj","xazjarqgfm","fxyfqbeoktcc","qrsjchxp","iltaqzawhgu","sgenjcfxr","yfikp","dvwhbyumthkiktb","walsx","jyajrkcvysicisab","brdeumb","tviihjwxdcz","dnrrgmem","ydgxlrjzucxyid","cdvdpvjlagwmg","ngnpxjkxims","gvyhnchlimsxc","w","jtizpezjl","qe","rjzv","vhnqvi","qm","iedzqswrsnfmnn","lt","utqfcqyrrwm","wtelvsqrru","fjwrhjcrtbcytn","qmqxceuohpiffaq","rmoybqjjgdyo","pmxttqftypfexlv","tg","qa","iqbqjlnpbf","kgaynkddbzllecd","tccvslp","curkxfoimnw","fvnyqkzlheruxr","iiygnzfov","coqs","oa","eiu","vzemmxtklis","lxu","nrwsjaxzwmh","tdayz","oxbbemejgosgcynf","ykbcn","hesvnctfvdsp","ku","rjhykpadahbhj","at","sxlngbtxmqr","wqrom","qzyabzrco","rbbyklndcqdj","cnsmgmwmpbgjq","krvnaf","qrwfajnfahyqocdb","fnlaozmff","vmoymbmytjvfcgt","cijyy","jdgwjbztl","swmalgbgpaplqgz","hfl","typttkrpfvx","tkzpzrscwbx","bwfqqvjcukjbsg","nxqmxr","x","eyavnz","il","dhthp","eyelg","npsoqsw","reogbmveofvusdsx","jvdrjkhxkq","qzjbrpljwuzpl","czqeevvbvcwh","vzuszqvhlmapty","yu","yldwwgezlqur","vorxwgdtgjilgydq","pknt","bgihl","ckorgrm","ixylxjmlfv","bpoaboylced","zea","igfagitkrext","ipvqq","dmoerc","oqxbypihdv","dtjrrkxro","rexuhucxpi","bvmuyarjwqpcoywa","qwdmfpwvamisns","bhopoqdsref","tmnm","cre","ktrniqwoofoeenbz","vlrfcsftapyujmw","updqikocrdyex","bcxw","eaum","oklsqebuzeziisw","fzgyhvnwjcns","dybjywyaodsyw","lmu","eocfru","ztlbggsuzctoc","ilfzpszgrgj","imqypqo","fump","sjvmsbrcfwretbie","oxpmplpcg","wmqigymr","qevdyd","gmuyytguexnyc","hwialkbjgzc","lmg","gijjy","lplrsxznfkoklxlv","xrbasbznvxas","twn","bhqultkyfq","saeq","xbuw","zd","kng","uoay","kfykd","armuwp","gtghfxf","gpucqwbihemixqmy","jedyedimaa","pbdrx","toxmxzimgfao","zlteob","adoshnx","ufgmypupei","rqyex","ljhqsaneicvaerqx","ng","sid","zagpiuiia","re","oadojxmvgqgdodw","jszyeruwnupqgmy","jxigaskpj","zpsbhgokwtfcisj","vep","ebwrcpafxzhb","gjykhz","mfomgxjphcscuxj","iwbdvusywqlsc","opvrnx","mkgiwfvqfkotpdz","inpobubzbvstk","vubuucilxyh","bci","dibmye","rlcnvnuuqfvhw","oorbyyiigppuft","swpksfdxicemjbf","goabwrqdoudf","yjutkeqakoarru","wuznnlyd","vfelxvtggkkk","mxlwbkbklbwfsvr","advraqovan","smkln","jxxvzdjlpyurxpj","ssebtpznwoytjefo","dynaiukctgrzjx","irzosjuncvh","hcnhhrajahitn","vwtifcoqepqyzwya","kddxywvgqxo","syxngevs","batvzmziq","mjewiyo","pzsupxoflq","byzhtvvpj","cqnlvlzr","akvmxzbaei","mwo","vg","ekfkuajjogbxhjii","isdbplotyak","jvkmxhtmyznha","lqjnqzrwrmgt","mbbhfli","bpeohsufree","ajrcsfogh","lucidbnlysamvy","tutjdfnvhahxy","urbrmmadea","hghv","acnjx","athltizloasimp","gu","rjfozvgmdakdhao","iephs","uztnpqhdl","rfuyp","crcszmgplszwfn","zihegt","xbspa","cjbmsamjyqqrasz","ghzlgnfoas","ljxl","cnumquohlcgt","jm","mfccj","hfedli","vtpieworwhyiucs","tdtuquartspkotm","pnkeluekvelj","ugrloq","zljmwt","fkyvqguqq","tpjidglpxqfxv","l","tvvimvroz","yy","opwyfovdz","pwlumocnyuoume","vjqpzkcfc","ihicd","dtttiixlhpikbv","goblttgvmndkqgg","gwsibcqahmyyeagk","prtvoju","lcblwidhjpu","kbu","pey","gkzrpc","bqajopjjlfthe","bc","lqs","zkndgojnjnxqsoqi","zyesldujjlp","drswybwlfyzph","xzluwbtmoxokk","bedrqfui","opajzeahv","lehdfnr","mnlpimduzgmwszc","velbhj","miwdn","wruqc","kscfodjxg","wcbm"}) << endl;
    return 0;
}
