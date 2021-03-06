// Teorema Chines do Resto
//
// Combina equacoes modulares lineares: x = a (mod m)
// O m final eh o lcm dos m's, e a resposta eh unica mod o lcm
// Os m nao precisam ser coprimos
// Se nao tiver solucao, o 'a' vai ser -1

ll gcde(ll a, ll b, ll& x, ll& y) {
	if (!a) {
		x = 0;
		y = 1;
		return b;
	}

	ll X, Y;
	ll g = gcde(b % a, a, X, Y);
	x = Y - (b / a) * X;
	y = X;

	return g;
}

struct crt {
	ll a, m;

	crt() : a(0), m(1) {}
	crt(ll a_, ll m_) : a(a_), m(m_) {}
	crt operator * (crt C) {
		ll x, y;
		ll g = gcde(m, C.m, x, y);
		if ((a - C.a) % g) a = -1;
		if (a == -1 or C.a == -1) return crt(-1, 0);
		ll lcm = m/g*C.m;
		ll ans = a + (x*(C.a-a)/g % (C.m/g))*m;
		return crt((ans % lcm + lcm) % lcm, lcm);
	}
};
