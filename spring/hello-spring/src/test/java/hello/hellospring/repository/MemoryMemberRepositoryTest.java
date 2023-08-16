package hello.hellospring.repository;

import hello.hellospring.domain.Member;
import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.Test;

import java.util.List;

import static org.assertj.core.api.AssertionsForClassTypes.assertThat;

class MemoryMemberRepositoryTest {
	// 테스트는 순서가 보장되지 않음. 위에서부터 순서대로 하는 게 아님.
	// 그래서 테스트 끝난 후 테스트한 데이터를 지워줘야함.
	MemoryMemberRepository repository = new MemoryMemberRepository();

	@AfterEach // 각 테스트가 끝나고 호출이 됨.
	public void afterEach() {
		repository.clearStore();
	}

	@Test
	public void save() {
		Member member = new Member();
		member.setName("spring");

		repository.save(member);

		Member result = repository.findById(member.getId()).get(); // optional 에서 값을 꺼낼 때
//		Assertions.assertEquals(member, result); // member 랑 result 랑 똑같은지 확인하는 메서드
//		// 성공하면 아무일도 없고, 실패하면 오류가 반환됨
		assertThat(member).isEqualTo(result);
	}

	@Test
	public void findByName() {
		Member member1 = new Member();
		member1.setName("spring1");
		repository.save(member1);

		Member member2 = new Member();
		member2.setName("spring2");
		repository.save(member2);

		Member result = repository.findByName("spring1").get();

		assertThat(result).isEqualTo(member1);
	}

	@Test
	public void findAll() {
		Member member1 = new Member();
		member1.setName("spring1");
		repository.save(member1);

		Member member2 = new Member();
		member2.setName("spring2");
		repository.save(member2);

		List<Member> result = repository.findAll();

		assertThat(result.size()).isEqualTo(2);
	}
}
