/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:24:44 by sranaivo          #+#    #+#             */
/*   Updated: 2025/04/09 16:01:19 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat
{

	public:

		Bureaucrat();
		Bureaucrat( Bureaucrat const & src );
		Bureaucrat(const std::string& name, int grade);
		~Bureaucrat();

		//overloads
		Bureaucrat &		operator=( Bureaucrat const & rhs );

		// accessors
		const std::string& getName() const;
		int	getGrade() const;

		// methods
		void incrementGrade();
		void decrementGrade();

		class GradeTooHighException : public std::exception
		{
			private:
				const char* what() const throw();
				const char* _error_message;

			public:
				GradeTooHighException(const char *msg);
		};

		class GradeTooLowException : public std::exception
		{
			private:
				const char* what() const throw();
				const char* _error_message;

			public:
				GradeTooLowException(const char *msg);
		};

	private:
		const std::string	_name;
		int					_grade;
		static int			_maxGrade;
		static int			_minGrade;
};

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i );

#endif /* ****************************************************** BUREAUCRAT_H */