#include <iostream>
#include <string>
#include <vector>
#include <ctime> 
#include <cstdlib>
#include <algorithm>  
#include <map>

using namespace std;
const int L = 500;
const int u = 5;
const int v = 50;

map<int, char> msg = { {0, ' '}, {1,'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}, {6, 'f'}
, {7, 'g'}, {8, 'h'}, {9, 'i'}, {10, 'j'}, {11, 'k'}, {12, 'l'}, {13, 'm'}, {14, 'n'}, {15, 'o'}
, {16, 'p'}, {17, 'q'}, {18, 'r'}, {19, 's'}, {20, 't'}, {21, 'u'}, {22, 'v'}, {23, 'w'}, {24, 'x'}
, {25, 'y'}, {26, 'z'} };

map<char, int> msgT = { {' ', 0}, {'a', 1} , {'b', 2}, {'c', 3}, {'d', 4}, {'e', 5}, {'f', 6}
, {'g', 7}, {'h', 8}, {'i', 9}, {'j', 10}, {'k', 11}, {'l', 12}, {'m', 13}, {'n', 14}, {'o', 15}
, {'p', 16}, {'q', 17}, {'r', 18}, {'s', 19}, {'t', 20}, {'u', 21}, {'v', 22}, {'w', 23}, {'x', 24}
, {'y', 25}, {'z', 26} };

vector<string> words = { "ingeniousness", "overarched", "niblicks", "honoraria", "mastodons",
"carnalities", "swage", "reimposed", "laywomen", "shew", "adducers", "heelless", "suavity",
"mispronunciation", "masseur", "pressed", "miserabilia", "indelicacy", "faultlessly", "chuted",
"shorelines", "irony", "intuitiveness", "cadgy", "ferries", "catcher", "wobbly", "protruded",
"combusting", "unconvertible", "successors", "footfalls", "bursary", "myrtle", "photocompose",
"papular", "vocality", "octyls", "immunosuppressant", "condemnatory", "stupendous", "widish",
"empowering", "argue", "banned", "casuistry", "astonished", "foresightedly", "armlets", "amend" };

map<char, int> freq = { {' ', 100}, {'a', 30} , {'b', 8}, {'c', 19}, {'d', 17}, {'e', 42}, {'f', 5}
, {'g', 6}, {'h', 10}, {'i', 31}, {'j', 0}, {'k', 1}, {'l', 21}, {'m', 15}, {'n', 26}, {'o', 30}
, {'p', 12}, {'q', 0}, {'r', 29}, {'s', 45}, {'t', 24}, {'u', 19}, {'v', 4}, {'w', 6}, {'x', 0}
, {'y', 14}, {'z', 0} };

int main(int argc, const char * argv[]) {

	int t;
	bool testing = true;

	vector<string> dictOne;
	dictOne.push_back("surrenderee document spunkiest coquetted abatis leasehold nuclei fogginess genoa traitors blockbuster superpositions flams surprized honcho cetera to transmit psychol wintered gruntingly cheapness translation laborer lissomeness caravansaries reflexes overextends bitter uplift strate filler cupolaed automatic machree nonparasitic unashamed braggy typier potencies greyness gulped masonwork blandisher disks fadeaway origamis manurer olives engine looted whitehall imperils shadowbox jabbing exports");
	dictOne.push_back("tumble cooked twirled absinths ceca cheatery raters redeploy niacinamide offeree preventively tangibleness beamy oligarchical microbus intends galvanize indelible tubings overcools rollover maladroit logways frilling skinks affirmatively flatfoots oversleeps consignors completes espadrille booms repaved ofays keens dinosaurs rerouted consignments victimless psychophysical chuckle admissibility muleteer deescalating ovary bowwow assisi fore tubbiest vocatively filially preestablish lacquerers spr");
	dictOne.push_back("harmonizations pratique defoliated brashly elegancy henpeck ecumenicism valuta lingers acrobatic mismarriage fruitlessness pattering enables travois nymphs fratricides awakener ordure tribulation elicit nonviable guiles raucously euclidean evangelist preoperative pathogeny frames medium inviabilities retrains crankcase awkwarder stopwatch subclinical irrigators lettuce skidooed fonder teem funguses purviews longshot affaires wearing judo resettle antedate inoperable pinworm pumper annul anteposi");
	dictOne.push_back("hark reascended recedes inebriate flowery awkwarder waterbed complacency sikh compartmented dependably alliterations headache basketfuls malocclusions cubistic hint headdresses unfrocks keloidal translucent fidelities instructional graphed baker superb spectroscopies bismark uncanniest detachability letdown querulously unstack curdling chained pointy drippers larch spermicide inextricability anteed improvising jape imponderably lithographic winglets advents triplicating growling fescue salabilit");
	dictOne.push_back("enrollee pins datively armiger bisect installs taffeta compliances governorship laceworks preciousness bedizens immaculately disinfect nucleonics biremes mailbags behaves enhance floppiest brutisms registered silenced tuques oryxes coddler undersigned mackintosh misemployment peacemakers pleadings dandification platypuses swig doer reshowed quadrangles locutory encapsules bawdies woolpack valuated malodorously shill cryogenies known distr bonsai morale mirage skit aquacades pi overcommon flippan");
	string d;
	while (testing == true) {
		//input cipher text
		string inputCipher = "";
		cout << "Please Input a cipher text:";
		getline(cin, inputCipher);

		if (inputCipher.length() < L) {
			cout << inputCipher.length() << "The input is wrong Size of input please try again" << endl;
			exit(0);
		}
		//generate cipher array
		char cipher[L];
		for (int i = 0; i < L; i++) {
			cipher[i] = inputCipher[i, 4];
		}

		//get input
		string test;
		cout << endl;
		cout << "Is it test 1 or test 2? (type 1 or 2): ";
		cin >> test;
		cout << "Key Length: ";
		cin >> t;
		cout << endl;

		int index;
		vector<int> temp;
		//test 1
		if (test == "1") {
			int max = 0;
			//possibility of correct answer for each plaintext
			//generate Keys
			int prob[u];
			for (int i = 0; i < u; i++) {
				prob[i] = 0;
			}
			//for all five plain Text
			for (int i = 0; i < u; i++) {
				//for all values in L
				for (int j = 0; j < L; j++) {
					temp.push_back(((msgT[inputCipher[j]] - msgT[dictOne[i][j]]) + 27) % 27);
					if (j > t) {
						if (temp[j - t] == temp[j]) {
							//cout << temp[j - t] << " " << temp[j] << " ";
							prob[i] += 1;
						}
					}
				}
				temp.clear();
			}
			int pos = 0;
			for (int i = 0; i < 5; i++) {
				//cout << prob[i] << endl;
				if (prob[i] >= max) {
					max = prob[i];
					pos = i;
				}
			}
			cout << "The PlainText is: " << dictOne[pos] << endl;
		}

		//Test 2
		//Kasiski Analysis
		if (test == "2") {
			vector<string> vec;
			for (int i = 0; i < t; i++) {
				vec.push_back("");
			}
			for (int i = 0; i < L; i++) {
				vec[(i % t)] += inputCipher[i];
			}

			int prob = 0;
			int pos = 0;
			int max = 0;
			vector<int> key;
			//Kasisiki Analysis given key length
			cout << "Possible Key: ";
			for (int x = 0; x < t; x++) {
				for (int p = 0; p < 27; p++) {
					for (int i = 0; i < vec[x].length(); i++) {
						prob += freq[msg[(((msgT[vec[x][i]] - p) + 27) % 27)]];

						if (prob >= max) {
							max = prob;
							pos = p;
						}
					}
					prob = 0;
				}
				key.push_back(pos);
				cout << pos << " ";
				pos = 0;
				max = 0;
			}
			cout << endl;
			int ind;
			string plainText;
			//decrypt given key
			cout << "Decrypted Plaintext: ";
			for (int i = 0; i < L; i++) {
				for (int x = 0; x < 27; x++) {
					if (msg[x] == inputCipher[i]) {
						pos = key[(i % t)];
						ind = (((x - pos) + 27) % 27);

						plainText += msg[ind];

					}
				}
			}
			cout << plainText;
		}
		string finished;
		cout << endl;
		cout << "This was the result I got according to given Information" << endl;
		testing = false;
	}
	/*
	//KeyGen
		//for (int i = 0; i < t; i++) {
		//	cout << correct[i] << " ";
		//}
		//decrypt given key
		for (int i = 0; i < L; i++) {
			for (int x = 0; x < 27; x++) {
				if (msg[x] == inputCipher[i]) {
					pos = key[(i % t)];
					ind = (((x - pos) + 27) % 27);

					respond += msg[ind];

				}
			}
		}
	}
	recursive function
	if (plain.length() >= 60) {
		return;
	}

	for (int j = 0; j < plain.size(); j++) {
		keys.push_back(shiftCalculator(plain[j], cipher[j]));
	}
	for (int i = 0; i < keys.size(); i++) {
		cout << keys[i] << " ";
	}
	cout << endl;
	int r = 0;
	if (plain.length() >= (keySize * 2)) {
		for (int k = 0; k < keySize; k++) {
			if (r < k && keys[k] == keys[k] + keySize) {
				correct = keys;
				break;
			}
			r += 2;
		}
	}
	if (correct.empty() != true) {
		return;
	}
	keys.clear();

	for (int i = 0; i < words.size(); i++) {
		decryptRecursive(plain + " " + words[i], cipher, keySize);
	}

	Disregard below code: I attempted to guess the key using frequency to solve it without dictionary

	//Test 2
	map<int, string> keys;
	map<int, string> keysA;
	vector<int> freqA;
	for (int i = 0; i < 27; i++) {
		freqA.push_back(0);
	}
	string s;
	int ind;
	int shift = 0;
	int best = 0;

	if (test == "2") {
		for (int i = 0; i < t; i++) {
			for (int j = i; j < inputCipher.size(); j += t) {
				if (j <= inputCipher.size()) {
					s += inputCipher[j];
				}
			}
			keys[i] = s;
			s = "";
		}
		int val = 0;
		//for all possible key value at position i
		for (int i = 0; i < t; i++) {
			//for all value in key
			for (int l = 0; l < 27; l++) {
				for (int k = 0; k < keys[i].size(); k++) {
					for (int j = 0; j <27; j++) {
						if (keys[i][k] == msg[j]) {
							ind = (((j - l) + 27) % 27);
							s += msg[ind];
						}
					}
				}

				for (int z = 0; z < 27; z++) {
					freqA[z] = count(s, msg[z]);
				}

				for (int h = 0; h < freqA.size(); h++) {
					if (freq[msg[h]] > freqA[h]) {
						best += 1;
					}
				}
				if (best > 16) {
					cout << l;
				}
				freqA.clear();
				for (int rt = 0; rt < 27; rt++) {
					freqA.push_back(0);
				}
				best = 0;
				s = "";
			}
		}

	}

	Disregard below code: I attempted to solve by generating randon plaintext but didn't work out as intended

	Test 2
	if (test == "2") {
		//Key Generator
		vector<int> key;
		string word;
		int prob = 0;
		int i = 0;
		while (key.empty()) {
			while (word.size() < (27 * 2)+2) {
				word += (words[(rand() % words.size())] + " ");
			}
			for (i = 0; i < word.length(); i++) {
				for (int k = 0; k < 27; k++) {
					if (word[i] == msg[k]) {
						for (int l = 0; l < 27; l++) {
							if (inputCipher[i] == msg[l]) {
								key.push_back(index = ((l - k) + 27) % 27);
								//cout << msg[k] << " " << msg[l] << " " << index << endl;
							}
						}
					}
				}
				if (i > t) {
					if (key[i - t] == key[i]) {
						prob += 1;
					}
				}
			}
			if (prob < 40) {
				word = "";
				key.clear();
				prob = 0;
			}
		}
		for (int i = 0; i < t; i++) {
			cout << key[i] << " ";
		}
	*/

system("Pause");
return 0;
}

