/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC
Copyright (C) 2019 Trevor Laughlin and the pyOCCT contributors

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/
#include <pyOCCT_Common.hxx>
#include <TNaming_Evolution.hxx>

void bind_TNaming_Evolution(py::module &mod){

py::enum_<TNaming_Evolution>(mod, "TNaming_Evolution", "Defines the type of evolution in old shape - new shape pairs. The definitions - in the form of the terms of the enumeration - are needed by the TNaming_NamedShape attribute and indicate what entities this attribute records as follows: - PRIMITIVE - New entities; in each pair, old shape is a null shape and new shape is a created entity. - GENERATED - Entities created from other entities; in each pair, old shape is the generator and new shape is the created entity. - MODIFY - Split or merged entities, in each pair, old shape is the entity before the operation and new shape is the new entity after the operation. - DELETE - Deletion of entities; in each pair, old shape is a deleted entity and new shape is null. - SELECTED - Named topological entities; in each pair, the new shape is a named entity and the old shape is not used.")
	.value("TNaming_PRIMITIVE", TNaming_Evolution::TNaming_PRIMITIVE)
	.value("TNaming_GENERATED", TNaming_Evolution::TNaming_GENERATED)
	.value("TNaming_MODIFY", TNaming_Evolution::TNaming_MODIFY)
	.value("TNaming_DELETE", TNaming_Evolution::TNaming_DELETE)
	.value("TNaming_REPLACE", TNaming_Evolution::TNaming_REPLACE)
	.value("TNaming_SELECTED", TNaming_Evolution::TNaming_SELECTED)
	.export_values();


}