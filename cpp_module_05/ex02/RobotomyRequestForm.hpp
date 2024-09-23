#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm(const std::string &name);
		virtual ~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &a);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &a);

		virtual void execute(Bureaucrat const &executor) const;
	private:
		RobotomyRequestForm();
};
