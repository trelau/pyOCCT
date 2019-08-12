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
#include <GeomAbs_Shape.hxx>

void bind_GeomAbs_Shape(py::module &mod){

py::enum_<GeomAbs_Shape>(mod, "GeomAbs_Shape", "Provides information about the continuity of a curve: - C0: only geometric continuity. - G1: for each point on the curve, the tangent vectors 'on the right' and 'on the left' are collinear with the same orientation. - C1: continuity of the first derivative. The 'C1' curve is also 'G1' but, in addition, the tangent vectors ' on the right' and 'on the left' are equal. - G2: for each point on the curve, the normalized normal vectors 'on the right' and 'on the left' are equal. - C2: continuity of the second derivative. - C3: continuity of the third derivative. - CN: continuity of the N-th derivative, whatever is the value given for N (infinite order of continuity). Also provides information about the continuity of a surface: - C0: only geometric continuity. - C1: continuity of the first derivatives; any isoparametric (in U or V) of a surface 'C1' is also 'C1'. - G2: for BSpline curves only; 'on the right' and 'on the left' of a knot the computation of the 'main curvature radii' and the 'main directions' (when they exist) gives the same result. - C2: continuity of the second derivative. - C3: continuity of the third derivative. - CN: continuity of any N-th derivative, whatever is the value given for N (infinite order of continuity). We may also say that a surface is 'Ci' in u, and 'Cj' in v to indicate the continuity of its derivatives up to the order i in the u parametric direction, and j in the v parametric direction.")
	.value("GeomAbs_C0", GeomAbs_Shape::GeomAbs_C0)
	.value("GeomAbs_G1", GeomAbs_Shape::GeomAbs_G1)
	.value("GeomAbs_C1", GeomAbs_Shape::GeomAbs_C1)
	.value("GeomAbs_G2", GeomAbs_Shape::GeomAbs_G2)
	.value("GeomAbs_C2", GeomAbs_Shape::GeomAbs_C2)
	.value("GeomAbs_C3", GeomAbs_Shape::GeomAbs_C3)
	.value("GeomAbs_CN", GeomAbs_Shape::GeomAbs_CN)
	.export_values();


}