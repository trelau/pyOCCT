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
#include <GccEnt_Position.hxx>

void bind_GccEnt_Position(py::module &mod){

py::enum_<GccEnt_Position>(mod, "GccEnt_Position", "Qualifies the position of a solution of a construction algorithm with respect to one of its arguments. This is one of the following: - GccEnt_unqualified: the position of the solution is undefined with respect to the argument, - GccEnt_enclosing: the solution encompasses the argument, - GccEnt_enclosed: the solution is encompassed by the argument, - GccEnt_outside: the solution and the argument are external to one another, - GccEnt_noqualifier: the value returned during a consultation of the qualifier when the argument is defined as GccEnt_unqualified. Note: the interior of a line or any open curve is defined as the left-hand side of the line or curve in relation to its orientation.")
	.value("GccEnt_unqualified", GccEnt_Position::GccEnt_unqualified)
	.value("GccEnt_enclosing", GccEnt_Position::GccEnt_enclosing)
	.value("GccEnt_enclosed", GccEnt_Position::GccEnt_enclosed)
	.value("GccEnt_outside", GccEnt_Position::GccEnt_outside)
	.value("GccEnt_noqualifier", GccEnt_Position::GccEnt_noqualifier)
	.export_values();


}