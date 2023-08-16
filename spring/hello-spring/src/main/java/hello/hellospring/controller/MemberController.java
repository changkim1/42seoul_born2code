package hello.hellospring.controller;

import hello.hellospring.service.MemberService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;

@Controller // <- 컴포넌트 스캔 @Component 가 내장되어 있음
// 컴포넌트들을 스프링 빈으로 컨테이너에 등록
// Autowired 를 통해 연결시켜줌
public class MemberController {

	private final MemberService memberService;

	@Autowired // 생성자 호출시 스프링 컨테이너에 있는 MemberService 를 연결시켜줌
	// @Service, @Repository 랑 연결
	// MemberService 컨트롤러가 생성될 때
	public MemberController(MemberService memberService) {
		// MemberService 는 순수한 자바 클래스
		// @Service 를 MemberService 에 넣어줘야함
		this.memberService = memberService;
	}
}
