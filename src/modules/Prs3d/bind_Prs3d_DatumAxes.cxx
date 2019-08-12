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
#include <Prs3d_DatumAxes.hxx>

void bind_Prs3d_DatumAxes(py::module &mod){

py::enum_<Prs3d_DatumAxes>(mod, "Prs3d_DatumAxes", "Enumeration defining an axes used in datum aspect, see Prs3d_Datum.")
	.value("Prs3d_DA_XAxis", Prs3d_DatumAxes::Prs3d_DA_XAxis)
	.value("Prs3d_DA_YAxis", Prs3d_DatumAxes::Prs3d_DA_YAxis)
	.value("Prs3d_DA_ZAxis", Prs3d_DatumAxes::Prs3d_DA_ZAxis)
	.value("Prs3d_DA_XYAxis", Prs3d_DatumAxes::Prs3d_DA_XYAxis)
	.value("Prs3d_DA_YZAxis", Prs3d_DatumAxes::Prs3d_DA_YZAxis)
	.value("Prs3d_DA_XZAxis", Prs3d_DatumAxes::Prs3d_DA_XZAxis)
	.value("Prs3d_DA_XYZAxis", Prs3d_DatumAxes::Prs3d_DA_XYZAxis)
	.export_values();


}