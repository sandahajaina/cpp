/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:05:59 by sranaivo          #+#    #+#             */
/*   Updated: 2025/01/24 17:15:05 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{

	public:

		Ice();
		Ice( Ice const & src );
		~Ice();

		AMateria* clone() const;
		void use(ICharacter& target);

		Ice &		operator=( Ice const & rhs );

	private:

};

std::ostream &			operator<<( std::ostream & o, Ice const & i );

#endif /* ************************************************************* ICE_H */