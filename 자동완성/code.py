# 문제 해결을 위해 필요한 메소드를 Trie 클래스에 추가하고, 전체 로직을 재검토하겠습니다.
class TrieNode:
    def __init__(self):
        self.children = {}
        self.counter = 0  # 이 노드를 거쳐간 단어의 수를 세기 위한 카운터

class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word):
        node = self.root
        for char in word:
            if char not in node.children:
                node.children[char] = TrieNode()
            node = node.children[char]
            node.counter += 1  # 현재 노드를 거치는 단어 수 증가

    def count_inputs(self, words):
        total_count = 0
        for word in words:
            node = self.root
            count = 0
            for char in word:
                # 더 이상 구분할 필요가 없거나 마지막 문자에 도달하면 중지
                if node.counter == 1:
                    break
                node = node.children[char]
                count += 1
            total_count += count
        return total_count

def solution(words):
    trie = Trie()
    # 모든 단어를 트라이에 삽입
    for word in words:
        trie.insert(word)

    # 각 단어를 찾기 위해 입력해야 하는 최소한의 문자 수 계산
    return trie.count_inputs(words)

# 예제 입력으로 테스트
example_words = ["go", "gone", "guild"]
result = solution(example_words)
result