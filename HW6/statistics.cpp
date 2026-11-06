#include <iostream>
#include <limits>
#include <vector>

class IStatistics {
public:
	virtual ~IStatistics() {}

	virtual void update(double next) = 0;
	virtual double eval() const = 0;
	virtual const char * name() const = 0;
};

class Min : public IStatistics {
public:
	Min() : m_min{std::numeric_limits<double>::max()} {
	}

	void update(double next) override {
		if (next < m_min) {
			m_min = next;
		}
	}

	double eval() const override {
		return m_min;
	}

	const char * name() const override {
		return "min";
	}

private:
	double m_min = 0.0;
};

class Max : public IStatistics {
public:
	Max() : m_max{std::numeric_limits<double>::min()} {
	}

	void update(double next) override {
		if (next > m_max) {
			m_max = next;
		}
	}

    double eval() const override {
		return m_max;
	}

    const char * name() const override {
		 return "max";
	}
private:
    double m_max = 0.0;
};

class Mean : public IStatistics {
public:
    void update(double next) override {
        m_sum += next;
        ++m_count;
    }
    double eval() const override {
        return m_count == 0 ? 0.0 : m_sum / static_cast<double>(m_count);
    }
    const char * name() const override { return "mean"; }
private:
    double m_sum = 0.0;
    std::size_t m_count = 0;
};

// Смещённая оценка стандартного отклонения (деление на n):
//   S = sqrt( (1/n) * sum_i (x_i - mean)^2 )
class Std : public IStatistics {
public:
    void update(double next) override {
        m_values.push_back(next);      // копим все значения
        m_sum += next;
        ++m_count;
    }

    double eval() const override {
        if (m_count == 0) return 0.0;

        const double mean = m_sum / static_cast<double>(m_count);

        double sum_sq = 0.0;
        for (double x : m_values) {
            const double d = x - mean;
            sum_sq += d * d;
        }

        const double variance = sum_sq / static_cast<double>(m_count); // делим на n
        return std::sqrt(variance);
    }

    const char * name() const override { return "std"; }

private:
    std::vector<double> m_values;
    double m_sum   = 0.0;
    std::size_t m_count = 0;
};

int main() {

	constexpr std::size_t statistics_count = 4;
	IStatistics *statistics[statistics_count] = {
    new Min{}, new Max{}, new Mean{}, new Std{},
};

	double val = 0;
	while (std::cin >> val) {
		for (size_t i = 0; i < statistics_count; ++i) {
			statistics[i]->update(val);
		}
	}

	// Handle invalid input data
	if (!std::cin.eof() && !std::cin.good()) {
		std::cerr << "Invalid input data\n";
		return 1;
	}

	// Print results if any
	for (size_t i = 0; i < statistics_count; ++i) {
		std::cout << statistics[i]->name() << " = " << statistics[i]->eval() << std::endl;
	}

	// Clear memory - delete all objects created by new
	for (size_t i = 0; i < statistics_count; ++i) {
		delete statistics[i];
	}

	return 0;
}