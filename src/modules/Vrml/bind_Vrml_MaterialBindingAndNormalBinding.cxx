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
#include <Vrml_MaterialBindingAndNormalBinding.hxx>

void bind_Vrml_MaterialBindingAndNormalBinding(py::module &mod){

py::enum_<Vrml_MaterialBindingAndNormalBinding>(mod, "Vrml_MaterialBindingAndNormalBinding", "None")
	.value("Vrml_DEFAULT", Vrml_MaterialBindingAndNormalBinding::Vrml_DEFAULT)
	.value("Vrml_OVERALL", Vrml_MaterialBindingAndNormalBinding::Vrml_OVERALL)
	.value("Vrml_PER_PART", Vrml_MaterialBindingAndNormalBinding::Vrml_PER_PART)
	.value("Vrml_PER_PART_INDEXED", Vrml_MaterialBindingAndNormalBinding::Vrml_PER_PART_INDEXED)
	.value("Vrml_PER_FACE", Vrml_MaterialBindingAndNormalBinding::Vrml_PER_FACE)
	.value("Vrml_PER_FACE_INDEXED", Vrml_MaterialBindingAndNormalBinding::Vrml_PER_FACE_INDEXED)
	.value("Vrml_PER_VERTEX", Vrml_MaterialBindingAndNormalBinding::Vrml_PER_VERTEX)
	.value("Vrml_PER_VERTEX_INDEXED", Vrml_MaterialBindingAndNormalBinding::Vrml_PER_VERTEX_INDEXED)
	.export_values();


}