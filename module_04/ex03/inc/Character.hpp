/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:33:01 by sranaivo          #+#    #+#             */
/*   Updated: 2025/01/28 15:31:28 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class Character : public ICharacter
{

	public:

		Character();
		Character(const std::string& name);
		Character( Character const & src );
		~Character();

		Character &		operator=( Character const & rhs );

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);

	private:
		static int _inventoryNb;
		const std::string _name;
		AMateria* _materias[4];
		int _nbMateria;
		void _saveUnequippedMateria(AMateria*);
		AMateria* _unequippedMateria;

};

// std::ostream &			operator<<( std::ostream & o, Character const & i );

#endif /* ******************************************************* CHARACTER_H */