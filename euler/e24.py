from pylib import mathfn

perms = []

def permute():
    broken = False
    # appending the first digit
    num = 1
    count_a = range(10)
    for a in count_a:
        count_b = range(10)
        count_b.remove(a)
        for b in count_b:
            count_c = range(10)
            count_c.remove(a)
            count_c.remove(b)
            for c in count_c:
                count_d = range(10)
                count_d.remove(a)
                count_d.remove(b)
                count_d.remove(c)
                for d in count_d:
                    count_e = range(10)
                    count_e.remove(a)
                    count_e.remove(b)
                    count_e.remove(c)
                    count_e.remove(d)
                    for e in count_e:
                        count_f = range(10)
                        count_f.remove(a)
                        count_f.remove(b)
                        count_f.remove(c)
                        count_f.remove(d)
                        count_f.remove(e)
                        for f in count_f:
                            count_g = range(10)
                            count_g.remove(a)
                            count_g.remove(b)
                            count_g.remove(c)
                            count_g.remove(d)
                            count_g.remove(e)
                            count_g.remove(f)
                            for g in count_g:
                                count_h = range(10)
                                count_h.remove(a)
                                count_h.remove(b)
                                count_h.remove(c)
                                count_h.remove(d)
                                count_h.remove(e)
                                count_h.remove(f)
                                count_h.remove(g)
                                for h in count_h:
                                    count_i = range(10)
                                    count_i.remove(a)
                                    count_i.remove(b)
                                    count_i.remove(c)
                                    count_i.remove(d)
                                    count_i.remove(e)
                                    count_i.remove(f)
                                    count_i.remove(g)
                                    count_i.remove(h)
                                    for i in count_i:
                                        count_j = range(10)
                                        count_j.remove(a)
                                        count_j.remove(b)
                                        count_j.remove(c)
                                        count_j.remove(d)
                                        count_j.remove(e)
                                        count_j.remove(f)
                                        count_j.remove(g)
                                        count_j.remove(h)
                                        count_j.remove(i)
                                        for j in count_j:
                                            perms.append(str(a) +
                                                         str(b) +
                                                         str(c) +
                                                         str(d) +
                                                         str(e) +
                                                         str(f) +
                                                         str(g) +
                                                         str(h) +
                                                         str(i) +
                                                         str(j))
                                            num += 1
                                            if num > 1000000:
                                                broken = True
                                                break
                                    if broken: break
                                if broken: break
                            if broken: break
                        if broken: break
                    if broken: break
                if broken: break
            if broken: break
        if broken: break

if __name__ == '__main__':
    permute()
    print perms
