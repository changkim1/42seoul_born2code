package hello.hellospring.repository;

import hello.hellospring.domain.Member;
import org.springframework.stereotype.Repository;

import java.util.*;

@Repository // 스프링에 등록시킴
public class MemoryMemberRepository implements MemberRepository {

	private static Map<Long, Member> store = new HashMap<>();
	private static long sequence = 0L; // key 값 생성해주는 애

	@Override
	public Member save(Member member) {
		member.setId(++sequence);
		store.put(member.getId(), member);
		return member;
	}

	@Override
	public Optional<Member> findById(Long id) {
		return Optional.ofNullable(store.get(id));
	}

	@Override
	public Optional<Member> findByName(String name) {
		return store.values().stream()
				.filter(member -> member.getName().equals(name))
				.findAny(); // 루프를 돌면서 하나 찾아지면
		// 반환, 없으면 optional 에 null 포함 반환
	}

	@Override
	public List<Member> findAll() {
		return new ArrayList<>(store.values());
		// values -> store 에 있는 멤버들 (Members)
	}

	public void clearStore() {
		store.clear();
	}


}
